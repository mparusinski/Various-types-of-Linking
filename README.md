# Dangers of mixing static variables and dynamic linking

This simple Git project is about highlighting the dangers of initializing
static variables more than once in C++.

At the heart of this project is a Makefile which allows to compile the project
using static libraries, dynamic libraries or no libraries at all.

## Quick overview ##

The project is made of one executable linking against two libraries each defining the same static variable. The static variable allocates memory dynamically and hence upon deallocation (when the application terminates) a memory leak occurs.

*Note: This project runs on Linux*

### As one binary ###

You can compile the entire project as one single binary using the command:

```shell
make main_classic
```

GCC rightfully complains about a static variable being instantiated twice.

### As two static libraries

You can compile the project as one binary linked against two static libraries.

```shell
make main_static
```
GCC rightfully complains about a static variable being instantiated twice.

### As two dynamic libraries

You can compile the project as one binary linked against two dynamic libraries

```shell
make main_dynamic
```

GCC is unable to detect a variable being allocated twice and thus it compiles fine. Upon execution you will the program core.

## Project structure ##

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

## The why ##

This project highlights that static variable initialization can cause very obscure errors if used carelessly. This kind of problem most likely occur if you mix a lot of design patterns and abstraction.
