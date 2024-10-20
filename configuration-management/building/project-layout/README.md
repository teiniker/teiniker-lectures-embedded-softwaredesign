# Project Layout 

A project layout specifies the order of files within a C++ project.

Without a defined structure, C++ projects look like:

_Example:_ Flat project structure with all files in one folder
```
project
├── resistor.o
├── test
├── test.o
├── unity.o
├── unity.a
├── Makefile
├── README.md
├── resistor.cpp
├── resistor.h
└── test.cpp
```

A C/C++ project contains a number of **different file types**:
* Source files (*.cpp, *.h)
* Object files (*.o)
* Library files (*.a, *.so)
* Documentation files (*.txt, *.md) and images (*.png, *.jpg)
* …

We can group files based on:
* Manual written code vs. generated code
* Source code vs. compiled files
* Productive code vs. test code

There is no unique C++ project layout standard, but we can learn from existing projects...

## Simplified GNU Project Layout for C/C++

GNU projects store files in the following subdirectories:  
* **src**: Source code (C/C++ files and private header files).
* **include**: Header files (which are public).
* **test**: Source code for unit testing.
* **build**: Files produced by the compiler and linker (object files, executables).  
* **doc**: Documentation files. 
* **libs**: Third party libraries that are need by the project.

_Example:_ Project structure, organized in subdirectories
```
project
├── build
│   ├── resistor.o
│   ├── test
│   ├── test.o
│   ├── unity.o
│   └── unity.a
├── Makefile
├── doc
│   └── README.md
├── src
│   └── resistor.cpp
├── include
│   └── resistor.h
└── test
    └── test.cpp
```

This project structure separates source code, headers, tests, documentation, 
and build artifacts into distinct directories. 
This organization enhances modularity, maintainability, and scalability.


## References

* [Directory Layout and Source Conventions](https://gcc.gnu.org/onlinedocs/libstdc++/manual/source_organization.html)



*Egon Teiniker, 2020-2024, GPL v3.0*