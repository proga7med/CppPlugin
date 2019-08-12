#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include <algorithm>
#include <iterator>
#include <unordered_map>
#include "ifinalize.h"
#include "gcpp_global.h"

namespace GC {

    class GCPPSHARED_EXPORT GarbageCollector {
    public:
        static void collect();
        static void collect(IFinalize* object);
        static void keepAlive(IFinalize* object);
        static void suppressFinalize(IFinalize* object);
        static void waitToCallAllFinalize();
        static void waitToFinish();

        template<class T> static void Add(T* object) {
            bool isFinalize;

            isFinalize = std::is_polymorphic<T>::value ?
                         true : false;

            auto tempObj = (IFinalize*)object;
            m_collectorTable.insert({tempObj, isFinalize});
        }

    private:
        static std::unordered_map<IFinalize*, bool> m_collectorTable;
    };

    template<class T, class... _Types>
    T* gcnew(_Types&&... _Args){
        T* t = new T(_Args...);
        GarbageCollector::Add(t);
        return t;
    }

}

#endif // GARBAGECOLLECTOR_H
