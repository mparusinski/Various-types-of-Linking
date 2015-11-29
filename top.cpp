#include "top.h"

#include <iostream>
#include <new>

ClassWithNonTrivialDtor::ClassWithNonTrivialDtor(int initValue)
    : m_heapInt(nullptr)
{
    m_heapInt = new int;
    if (m_heapInt != nullptr)
        *m_heapInt = initValue;
}

ClassWithNonTrivialDtor::~ClassWithNonTrivialDtor()
{
    delete m_heapInt;
}

ClassWithStaticVar::ClassWithStaticVar(int initValue)
    : m_nastyObject(initValue)
{
    std::cout << "Construction static object with value " << initValue << std::endl;
}

ClassWithStaticVar::~ClassWithStaticVar()
{
    std::cout << "Destruction static object" << std::endl;
}
