#include "gcobject.h"

namespace GC {

    Object::Object() {
        m_pFinalize = nullptr;
        m_KeepAlive = false;
        m_OrignalClassName = "";
        m_IsFinalizeSupressed = false;
        m_IsInhiertedFromIFinalize = false;
    }

    Object::Object(IFinalize* pFinalize, std::string orignalClassName, bool isInhiertedFromIFinalize, bool isFinalizeSupressed, bool keepAlive) {
        m_pFinalize = pFinalize;
        m_KeepAlive = keepAlive;
        m_OrignalClassName = orignalClassName;
        m_IsFinalizeSupressed = isFinalizeSupressed;
        m_IsInhiertedFromIFinalize = isInhiertedFromIFinalize;
    }

    IFinalize* Object::getFinalize() const {
        return m_pFinalize;
    }

    void Object::setKeepAlive(bool keepAlive) {
        m_KeepAlive = keepAlive;
    }

    void Object::setInhiertedFromIFinalize(bool inhiertedFromIFinalize) {
        m_IsInhiertedFromIFinalize = inhiertedFromIFinalize;
    }

    void Object::setFinalizeSupressed(bool finalizeSupressed) {
        m_IsFinalizeSupressed = finalizeSupressed;
    }

    const bool Object::isKeepAlive() const {
        return m_KeepAlive;
    }

    const bool Object::isInhiertedFromIFinalize() const {
        return m_IsInhiertedFromIFinalize;
    }

    const bool Object::isFinalizeSupressed() const{
        return m_IsFinalizeSupressed;
    }

    const std::string Object::getOrignalClassName() const {
        return m_OrignalClassName;
    }

    bool Object::operator ==(const Object& left) const {
        return (left.getFinalize() == getFinalize())
                && (left.getOrignalClassName() == getOrignalClassName())
                && (left.isFinalizeSupressed() == isFinalizeSupressed())
                && (left.isInhiertedFromIFinalize() == isInhiertedFromIFinalize())
                && (left.isKeepAlive() == isKeepAlive());
    }

}
