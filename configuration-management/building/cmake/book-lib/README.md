# CMake: Book Example Using a Library 

In this example, a static library `libbook.a` is first built from the 
`book.cpp` implementation, which is then linked to the executable.

**Static libraries** are archives of object files that are linked into 
executables at compile time.


## Create CMakeLists.txt
In order to build this simple project, we create a file named `CMakeLists.txt` 
in the root of your project directory with the following content:

```CMake
cmake_minimum_required(VERSION 3.25)
project(book LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(book STATIC book.cpp)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE book)
```

`CMakeLists.txt` components:

* **add_library(book STATIC book.cpp)**: Defines a new library target named `book`.
    The keyword `STATIC` specifies that the library is a static library. 
    Other types include `SHARED` for dynamic/shared libraries and `MODULE` for 
    plugin modules.

* **target_link_libraries(main PRIVATE book)**: Links the `book` library to the main 
    executable.
    The keyword `PRIVATE` specifies the scope of the linkage.
    * **PRIVATE**: The linked library `book` is only used internally by main. 
        It won't propagate to other targets that might link against `main`.
    * **PUBLIC**: The linkage is required both by `main` and any target that links 
        against `main`.
    * **INTERFACE**: The linkage is only required by targets that link against `main`, 
        not by `main` itself.



## Build the Project

Follow these steps to build your project using CMake:

```
$ cmake -S . -B build
$ cmake --build build
```

## Run the Executable

After a successful build, we can run the generated executable:

```
$ ./build/main
```


## References

* Rafał Świdziński. **Modern CMake for C++: Discover a better approach to building, testing, and packaging your software**. Packt Publishing, 2022.

	
*Egon Teiniker, 2020-2024, GPL v3.0*

