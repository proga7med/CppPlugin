#ifndef IFINALIZE_H
#define IFINALIZE_H

#include "gcpp_global.h"

namespace GC {

    class GCPPSHARED_EXPORT IFinalize {
    public:
        virtual void finalize() = 0;
    };

}

#endif // IFINALIZE_H
