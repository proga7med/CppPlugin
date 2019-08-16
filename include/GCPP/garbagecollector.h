#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include <list>
#include <mutex>
#include <thread>
#include <algorithm>

#include "gcobject.h"
#include "ifinalize.h"
#include "gcpp_global.h"

namespace GC {

    class GarbageCollector {
    public:
        static void collect();
        static void collect(IFinalize **object);
        static void keepAlive(IFinalize* object);
        static void suppressFinalize(IFinalize* object);
        static void waitToCallAllFinalize();
        static void waitToFinish();

        template<class T> static void Add(T* object) {
            bool isFinalize;

            isFinalize = std::is_polymorphic<T>::value ?
                         true : false;

            auto tempObj = (IFinalize*)object;
            Object obj (tempObj, typeid(object).name(), isFinalize);
            m_CollectorObjs.push_back(obj);
        }

    private:
        static std::list<Object> m_CollectorObjs;
        static std::mutex m_Mutex;
    };

    template<class T, class... _Types>
    T* gcnew(_Types&&... _Args){
        T* t = new T(_Args...);
        GarbageCollector::Add(t);
        return t;
    }

}

#endif // GARBAGECOLLECTOR_H
