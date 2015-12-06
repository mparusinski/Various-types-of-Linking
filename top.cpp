#include "top.h"

#include <iostream>
#include <new>

ClassWithNonTrivialDtor::ClassWithNonTrivialDtor(int initValue)
    : m_heapInt(NULL)
{
    m_heapInt = new int;
    if (m_heapInt != NULL)
        *m_heapInt = initValue;
}

ClassWithNonTrivialDtor::~ClassWithNonTrivialDtor()
{
    delete m_heapInt;
}

ClassWithStaticVar::ClassWithStaticVar(int initValue)
{
    std::cout << "Construction static object with value " << initValue << std::endl;
    m_nastyObject = new ClassWithNonTrivialDtor(initValue);
}

ClassWithStaticVar::~ClassWithStaticVar()
{
    std::cout << "Destruction static object" << std::endl;
    delete m_nastyObject;
}
