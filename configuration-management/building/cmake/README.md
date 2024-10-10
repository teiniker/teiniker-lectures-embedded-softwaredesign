# CMake 

CMake is an open-source, **cross-platform build system generator** that 
streamlines the process of compiling and managing software projects. 

By using simple configuration files called `CMakeLists.txt`, CMake 
automatically generates native build scripts (such as Makefiles or 
Visual Studio project files) tailored to the target platform and 
environment. 


## CMakeLists.txt

The primary configuration file for CMake  is named `CMakeLists.txt`.

It contains **directives and commands** that define how the project 
should be built.
     
Typically placed in the **root directory of our project** and can 
also be present in subdirectories for larger projects.

### Basic Commands
* `cmake_minimum_required(VERSION x.y)`: Specifies the minimum CMake version required.
* `project(Name [LANGUAGES ...])`: Defines the project name and the programming languages used.
* `add_executable(name [sources...])`: Adds an executable target to the build.
* `add_library(name [STATIC | SHARED | MODULE] [sources...])`: Adds a library target.
* `target_link_libraries(target library...)`: Specifies which libraries to link against a target.

### Variables and Cache

* **Variables**: Store values that can be reused throughout CMakeLists.txt.

    _Example_: `set(SOURCE_FILES main.cpp utils.cpp)`

* **Cache Variables**: 
    Persist between CMake runs and can be modified by users via command line or GUI.

    _Example_: `set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")`

### Targets

A target is an **output of the build process**, such as an executable or a library.

* **Types**:
    * **Executable**: Created using `add_executable()`.
    * **Library**: Created using `add_library()`.

* **Properties**: Targets have properties that define their behavior, such as 
    include directories, compile options, etc.

### Generators and Build Systems

CMake can **generate build scripts** for various native build systems.

**Common Generators**:
* **Unix Makefiles**: Generates Makefiles for use with make.
* **Ninja**: Generates build files for the Ninja build system.
* **Visual Studio**: Generates project and solution files for Visual Studio IDE.

_Example:_ Specify the generator
```
$ cmake -G "Ninja" ..
```

###  Out-of-Source Builds

Building the project in a separate directory (build tree) from the source code
(source tree).

```
$ cmake -S . -B build
$ cmake --build build
```

In older CMake versions we have to use:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
**Benefits**:
* Keeps the source tree clean.
* Allows multiple build configurations (e.g., Debug, Release) without interference.


###  Modularization and Subdirectories

* `add_subdirectory()`: Incorporates another `CMakeLists.txt` from a subdirectory, 
    enabling modular project structures.

_Example: Adding project subdirectories 
```
add_subdirectory(src)
add_subdirectory(test)
```

**Benefits**:
* Organizes large projects into manageable components.
* Facilitates reusability and separation of concerns.


## Examples

The following examples show the individual CMake configurations in use:

* [Simple project (only one directory)](book/)

* [Simple project creating and linking a library](book-lib/)

* [Simple project using Google Tests](book-test/)

* [Project using subdirectories and Google Tests](book-layout/)


## References

* [CMake Homepage](https://cmake.org/)

* [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

	
*Egon Teiniker, 2020-2024, GPL v3.0*