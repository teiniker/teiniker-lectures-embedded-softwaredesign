# GoogleTest Framework

GoogleTest is a testing framework developed by the Testing Technology team with 
Google’s specific requirements and constraints in mind. 

## Setup GoogleTest

GoogleTest can be built directly from the source code. To do this, the source 
code is cloned from Github and built with cmake:

```
$ cd Downloads/
$ git clone https://github.com/google/googletest
$ cd googletest/
$ cmake -S . -B build
$ cd build/
$ make
$ sudo make install 
```

The libraries and header files are installed in the following locations:
```
$ ll /usr/local/lib/libgmock.a
$ ll /usr/local/include/gtest/gtest.h
```

These are standard locations so the library can be used directly by the linker:
```
$ g++ test.cpp -o test -lgtest -lgtest_main -pthread
```

* **-lgtest**: This flag links our program against the GoogleTest library 
    (`libgtest.a` or `libgtest.so`).

    The **GoogleTest Library** (`libgtest`) provides the core functionalities 
    of the GoogleTest framework, including various macros, test case 
    definitions, and assertion mechanisms.

* **-lgtest_main**: This flag links against the GoogleTest Main library 
    (`libgtest_main.a` or `libgtest_main.so`).

    The **GoogleTest Main Library** (`libgtest_main`) provides a default `main()` 
    function for your test executable.    

* **-pthread**: This flag enables POSIX Threads (pthreads) support both 
    during compilation and linking. It performs two primary functions:
    * **Compilation Flags**: Defines the macro _REENTRANT and enables 
        thread-safe code compilation. This is essential for code that 
        uses threading constructs to ensure proper synchronization and 
        concurrency.
    * **Linker Flags**: Links against the pthread library (`libpthread`). 
        This library provides functions and types for creating and managing 
        threads, mutexes, condition variables, and other synchronization 
        primitives.

    GoogleTest may use threading internally to manage **parallel test execution**,
    handle asynchronous operations, or perform other tasks that benefit from
    multi-threading.

    Some parts of the GoogleTest library or your test code might explicitly 
    use pthreads for synchronization or concurrent operations.

## References
* [GoogleTest User’s Guide](https://google.github.io/googletest/)

* [YouTube: Introduction to Google Test and Google Mock](https://youtu.be/N8a7IFPAPXs?si=zYIqGOk5jvBA_TX0)

* [YouTube (Amir Kirsh): Back to Basics: C++ Testing - CppCon 2022](https://youtu.be/SAM4rWaIvUQ?si=YJS6xIkRIOeYVy-b)

*Egon Teiniker, 2020-2024, GPL v3.0*
