#include "garbagecollector.h"

namespace GC {

    std::unordered_map<IFinalize*, bool> GarbageCollector::m_collectorTable;

    void GarbageCollector::collect() {
        auto iterator = m_collectorTable.begin();
         while (iterator != m_collectorTable.end()) {
            auto tempObj = iterator->first;

            if(iterator->second == true) tempObj->finalize();
            iterator = m_collectorTable.erase(iterator);
            delete tempObj;
        }
    }

    void GarbageCollector::collect(IFinalize* object) {
        auto iterator = m_collectorTable.find(object);
        while (iterator != m_collectorTable.end()) {
            auto tempObj = iterator->first;
            if(tempObj != nullptr) {
                if(iterator->second == true) tempObj->finalize();
                delete tempObj;
            }
        }

    }

    void GarbageCollector::keepAlive(IFinalize* object) {

    }

    void GarbageCollector::suppressFinalize(IFinalize* object) {

    }

    void GarbageCollector::waitToCallAllFinalize() {

    }

    void GarbageCollector::waitToFinish() {

    }

}
