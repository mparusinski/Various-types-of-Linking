# Dangers of mixing static variables and dynamic linking

This simple Git project is about highlighting the dangers of initializing
static variables more than once in C++.

At the heart of this project is a Makefile which allows to compile the project
using static libraries, dynamic libraries or no libraries at all.

## Project structure

### top.h / top.cpp ###

 This file defines a class **ClassWithNonTrivialDtor** which has a non-trivial destructor which deallocates dynamically allocated memory.

 This include file also defines **ClassWithStaticVar** which contains an uninitialized static variable of type **ClassWithStaticVar**. **ClassWithStaticVar** objects contains a pointer to an object of type **ClassWithNonTrivialDtor**

The idea is that on the heap there is a static variable, which does potentially dangerous memory operations.

### right.h / right.cpp ###

This file defines a dummy class **DummyRight**, only for the purpose of having main.cpp instantiate an object which is defined in *right.cpp*. *right.cpp* instantiates the static variable from **ClassWithStaticVar**

### left.h / left.cpp ###

This file defines a dummy class **DummyLeft**, only for the purpose of having main.cpp instantiate an object which is defined in *left.cpp*. *left.cpp* instantiates the static variable from **ClassWithStaticVar**

### main.cpp ###

This file contains a very simple main function which creates
an object of type **DummyLeft** and an object of type **DummyRight**.
