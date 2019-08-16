#include "garbagecollector.h"
#include <iostream>

namespace GC {

    std::mutex GarbageCollector::m_Mutex;
    std::list<Object> GarbageCollector::m_CollectorObjs;

    void GarbageCollector::collect() {
        std::thread thread([&]{
            std::lock_guard<std::mutex> lock(m_Mutex); {
                for(const auto& obj : m_CollectorObjs) {
                    if(obj.isInhiertedFromIFinalize() && !obj.isFinalizeSupressed()) obj.getFinalize()->finalize();
                    auto tempObj = obj.getFinalize();
                    delete tempObj;
                    tempObj = nullptr;
                    m_CollectorObjs.remove(obj);
                }
            }
        });
    }

    void GarbageCollector::collect(IFinalize **object) {
        std::lock_guard<std::mutex> lock(m_Mutex); {
            for(const Object& obj : m_CollectorObjs) {
                std::cout << obj.getOrignalClassName() << std::endl;
                std::cout << obj.getFinalize() << std::endl;
                if(obj.getFinalize() != *object) continue;
                if(obj.isInhiertedFromIFinalize()) obj.getFinalize()->finalize();
                auto tempFinalizePtr = obj.getFinalize();
                delete tempFinalizePtr;

                *object = nullptr;
                m_CollectorObjs.remove(obj);
                break;
            }
        }
    }

    void GarbageCollector::keepAlive(IFinalize* object) {
        std::thread thread([&]{
            std::lock_guard<std::mutex> lock(m_Mutex); {
                for(auto &obj : m_CollectorObjs) {
                     if(obj.getFinalize() != object) continue;
                     obj.setKeepAlive(true);
                }
            }
        });
    }

    void GarbageCollector::suppressFinalize(IFinalize* object) {
        std::thread thread([&]{
            std::lock_guard<std::mutex> lock(m_Mutex); {
                for(auto &obj : m_CollectorObjs) {
                     if(obj.getFinalize() != object) continue;
                     obj.setFinalizeSupressed(true);
                }
            }
        });
    }

    void GarbageCollector::waitToCallAllFinalize() {

    }

    void GarbageCollector::waitToFinish() {

    }

}
