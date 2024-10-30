# First Steps: From C to C++ 

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

* [Function Overloading](function-overloading/)

* [Default Arguments](default-arguments/)

* [References](references/)


Many of these language extensions incur **little to no overhead compared 
to C code** and can therefore also be used in embedded systems.


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2024, GPL v3.0*
