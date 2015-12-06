#include "left.h"
#include <iostream>

DummyLeft::DummyLeft() {
	std::cout << "Constructing a DummyLeft object" << std::endl;
}
	
DummyLeft::~DummyLeft() {
	std::cout << "Destroying a DummyLeft object" << std::endl;
}

ClassWithStaticVar ClassWithStaticVar::instance(1);