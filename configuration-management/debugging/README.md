# Debugging 

Debugging is the **systematic process of identifying, analyzing, and resolving 
defects** or "bugs" within software or hardware systems. 

It involves isolating the source of an issue, understanding its cause, and 
implementing fixes to ensure the system operates as intended. 

Debugging employs various **tools and techniques** — such as breakpoints, 
step execution, and logging — to trace program execution and examine variable 
states. 

Effective debugging not only corrects errors but also **enhances the overall 
quality and reliability** of the system by uncovering underlying issues that 
might affect performance or security.


## Configure CMake 

The following CMake settings are necessary to debug programs.
Please note that these settings are only useful during development.

* `add_compile_options(-Wall -Wextra -Wpedantic)`: This command globally enables 
    specific compiler warning flags for all targets in the CMake project. 
    The flags `-Wall`, `-Wextra`, and `-Wpedantic` instruct the compiler to 
    produce warnings about various potential issues in the code, enhancing code 
    quality and maintainability.
    * `-Wall`: Enables all the commonly used warning messages.
        Helps identify potential issues that are not strictly errors but could 
        lead to bugs or undefined behavior.
    * `-Wextra`: Activates additional warning flags beyond those enabled by -Wall.
        Catches more subtle issues, providing a higher level of scrutiny in the 
        codebase.
    * -`Wpedantic`: Enforces strict ISO compliance by issuing warnings for code that 
        may not adhere to the C++ standard.
        Encourages writing portable and standards-compliant code, preventing reliance 
        on compiler-specific extensions.

    Instead of applying warning flags globally, it's often better to set them on 
    a per-target basis using `target_compile_options`. This approach provides 
    greater control and flexibility.

* `set(CMAKE_BUILD_TYPE Debug)`: This command sets the build configuration type to Debug, 
    influencing how the compiler and linker build the project. The Debug build type is 
    tailored for development and debugging, enabling features that facilitate debugging 
    and disable optimizations that might obscure the code's behavior.
    The Debug build type enables the compiler flags: `-g`, and `-O0`.

    Instead of setting the build type within `CMakeLists.txt`, allow users to specify 
    it during the configuration step. This approach supports flexibility and accommodates 
    various build scenarios.
    ```bash
        $ cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
    ```

* `find_package(GTest REQUIRED)`: This command searches for the **Google Test (GTest) framework** 
    within the system and makes its components available for use in the CMake project. 
    The `REQUIRED` keyword indicates that the package must be found; otherwise, CMake will 
    terminate with an error.


## Configure VS Code

To debug an executable which we have built using `cmake`, we have to change the `launch.json` 
file: 
* **Remove the "preLaunchTask" element** to stop automatic compiling before the debugging:

  Remove the following line:
  ```
    "preLaunchTask": "C/C++: gcc build active file",
  ```  

* **Change the "program" element** to point to the executable created by make within the `build` folder:

  Change from:  
  ```
    "program": "${fileDirname}/${fileBasenameNoExtension}", 
  ```  
  to:	 
  ```
    "program": "${fileDirname}/build/${fileBasenameNoExtension}",    
  ```    

Note that we have to open the `test.cpp` file before we start the debugger because the 
`${fileBasenameNoExtension}` variable contains the current opened file's basename.

Here the final `launch.json` file:
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/build/${fileBasenameNoExtension}", //!! change
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
        
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```

## Dynamic Memory Analysis

**Memory management** is a crucial aspect of C++ programming due to the language's 
design philosophy and its balance between performance, control, and flexibility. 
Understanding and effectively managing memory in C++ is essential for creating 
robust, efficient, and secure applications.

**Valgrind** is a powerful instrumentation framework primarily used for building 
dynamic analysis tools that aid developers in debugging and profiling their applications. 

Valgrind operates by running programs on a synthetic CPU, intercepting and monitoring 
various operations to detect a range of memory-related issues without requiring any 
modifications to the source code.

* **Detecting Memory Leaks**: Memory leaks occur when a program allocates memory but 
    fails to release it back to the system, leading to increased memory consumption 
    over time. Valgrind identifies these leaks, helping developers ensure efficient 
    memory usage.

* **Identifying Invalid Memory Accesses**: Programs might inadvertently read from or 
    write to memory locations that they shouldn't access, leading to undefined behavior 
    or crashes. Valgrind detects such invalid reads and writes, including accessing 
    freed memory or buffer overflows.

* **Tracking Memory Mismanagement**: Valgrind can identify issues like use of uninitialized 
    memory, double frees (attempting to free memory that has already been freed), and 
    mismatched memory management routines (e.g., using malloc with delete).

Integrating Valgrind into the development and testing lifecycle fosters proactive 
identification and resolution of memory-related issues, ultimately leading to more 
stable and secure applications.


## References

*  David J Agans. **Debugging: The 9 Indispensable Rules for Finding Even the Most Elusive Software and Hardware Problems**. AMACOM, 2006.

* Rafał Świdziński. **Modern CMake for C++**. Packt Publishing, 2022.

* [Valgrind Home](https://valgrind.org/)

*Egon Teiniker, 2020-2024, GPL v3.0*