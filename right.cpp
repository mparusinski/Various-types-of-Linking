#include "right.h"
#include <iostream>

DummyRight::DummyRight() {
	std::cout << "Constructing a DummyRight object" << std::endl;
}
	
DummyRight::~DummyRight() {
	std::cout << "Destroying a DummyRight object" << std::endl;
}

ClassWithStaticVar ClassWithStaticVar::instance(-1);