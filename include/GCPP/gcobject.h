#ifndef GCOBJECT_H
#define GCOBJECT_H

#include <string>
#include "ifinalize.h"

namespace GC {

    class Object {
    public:
        Object();
        Object(IFinalize* pFinalize, std::string orignalClassName, bool isInhiertedFromIFinalize, bool isFinalizeSupressed = false, bool keepAlive = false);
        IFinalize* getFinalize() const;
        void setInhiertedFromIFinalize(bool inhiertedFromIFinalize);
        void setFinalizeSupressed(bool finalizeSupressed);
        void setKeepAlive(bool keepAlive);
        const bool isInhiertedFromIFinalize() const;
        const bool isFinalizeSupressed() const;
        const bool isKeepAlive() const;
        const std::string getOrignalClassName() const;
        bool operator ==(const Object& left) const;

    private:
        IFinalize* m_pFinalize;
        bool m_IsInhiertedFromIFinalize;
        bool m_IsFinalizeSupressed;
        bool m_KeepAlive;
        std::string m_OrignalClassName;
    };

}

#endif // GCOBJECT_H
