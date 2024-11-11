# First Steps in C++ 

## What We (Should) Know From C

For an **introduction to C programming** with lots of examples, check out the 
[Computer Science and Programming in C/C++](https://github.com/teiniker/teiniker-lectures-computerscience) 
repository before moving on to C++.

The following C topics are **particularly important** in the context of C++ 
programming.

* [Functions](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/programming-c/c-basics/functions)

    A function is a **self-contained block of code** designed to perform 
    a specific task, which can be called and reused multiple times within 
    a program. 
    
    Each function has a defined return type, a name, and may accept parameters 
    (inputs) to operate on. 

    By encapsulating functionality, functions promote code reuse and reduce 
    redundancy, allowing developers to build complex programs by combining simpler, 
    well-defined components.


* [Structures](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/programming-c/c-basics/structures)

    A structure is a **composite data type** that allows you to group variables of 
    different types together under a single name:
    * The members of a structure can have different types.
    * The members of a structure have names. To select a particular member, 
        we specify its name, not its position.
    
    This capability is particularly useful for organizing data into a more meaningful 
    and manageable format. 

* [Memory Management](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/programming-c/c-advanced/memory-management)

    Memory management involves manually handling the **allocation and deallocation 
    of memory** during a program's execution. 
    Developers use functions like `malloc()`, `calloc()`, and `realloc()` to 
    allocate memory on the heap for dynamic data structures, and `free()` to 
    release that memory when it's no longer needed. 
    
    Proper memory management is crucial to prevent issues such as **memory leaks**, 
    where allocated memory is not freed, and **dangling pointers**, which occur 
    when pointers reference freed memory. 
    
    Unlike some higher-level languages, C does not provide automatic garbage collection, 
    so careful handling of memory is essential for efficient and error-free programs.

* [Modular Programming](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/programming-c/c-advanced/modular-programming/modules)

    Modular programming involves organizing code into separate, manageable components 
    or modules, each responsible for a specific functionality. 
    This is typically achieved by dividing the code into:
    * **Header Files (.h)** :
        * Contain declarations of functions, macros, constants, and data structures.
        * Serve as an interface, allowing different modules to understand how to 
            interact with each other without exposing the underlying implementation 
            details.
        * Are included in other `.c` files using the #include directive, enabling 
            code reuse and easier maintenance.
    * **Implementation Files (.c)**:
        * Contain the actual definitions and logic of the functions declared in 
            the header files.
        * Implement the functionality specified by the header, keeping the internal 
            workings hidden from other modules.
        * Can be compiled separately (into object files) and linked together to form 
            the final executable.

    This separation enhances code readability, maintainability, and reusability, as 
    developers can work on different modules independently. 
    It also facilitates encapsulation, ensuring that changes in one module's 
    implementation do not directly affect others, provided the interface remains 
    consistent.



## From C to C++ 

Modern C++ compilers will accommodate most of your C programming habits. 
This makes it easy to embrace a few of the tactical niceties that the C++ language 
affords us while deliberately avoiding the language’s deeper themes. 

This style of C++ is important to discuss for several reasons: 
* Seasoned C programmers can immediately benefit from applying simple, tactical-level C++ concepts to their programs. 
* It is not fully comprehensive C++. Simply sprinkling references and instances of 
  auto around a C program might make your code more robust and readable, but we’ll 
  need to learn other concepts to take full advantage of it. 
* In some environments (embedded software and heterogeneous computing), the 
  available tool chains have incomplete C++ support.

It’s possible to benefit immediately from at least **some C++ idioms**:

* [Namespaces](namespaces/)
    Namespaces in C++ are used to organize code into **logical groups** 
    and prevent name conflicts in large projects by providing a 
    **distinct scope for identifiers** such as variables, functions, 
    and classes.

* [Auto Initialization](auto-initialization/)
    Auto-initialization in C++ allows for the **automatic deduction of 
    the type of a variable** from its initializer, simplifying code and 
    improving readability.

* [Implicit typedef](implicit-typedef/)
    In C++, `struct` names are automatically treated as types, so `typedef` 
    isn’t needed for convenience. We can directly define a new type without 
    explicitly defining it as a `typedef`.

* [Function Overloading](function-overloading/)
    This feature allows multiple functions with the same name to be 
    defined in the same scope, differentiated by their parameter types 
    and/or counts, enabling different behaviors based on arguments passed.

* [Default Arguments](default-arguments/)
    Default arguments allow you to set a default value for a function's 
    parameters, so if an argument is not provided during a call, the 
    function will use the specified default.

* [References](references/)
    A reference is an alias for another variable, created using the `&` 
    symbol, enabling direct modification of the variable it references 
    without needing pointers.

Many of these language extensions incur **little to no overhead compared 
to C code** and can therefore also be used in embedded systems.


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2024, GPL v3.0*
