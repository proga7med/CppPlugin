#include <iostream>
#include "GCPP/garbagecollector.h"
#include "gtest/gtest.h"

class myClass : public GC::IFinalize {
  public:
    myClass(int x) {
        m_X = x;
    }

    int getX() {
        return m_X;
    }

protected:

    virtual void finalize() {
        m_X = 0;
    }

private:
    int m_X;
};

myClass* mycls;

TEST(testGC, testGcnew) {
    mycls = GC::gcnew<myClass>(10);
    ASSERT_EQ(mycls->getX(), 10);
    delete mycls;
    mycls = nullptr;
}

TEST(testGC, testCollect) {
    mycls = GC::gcnew<myClass>(10);
    GC::GarbageCollector::collect((GC::IFinalize**)&mycls);
    ASSERT_EQ(mycls, nullptr);
}
