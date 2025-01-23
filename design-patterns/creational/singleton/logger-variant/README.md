# Example: Singleton (Variant) - Logger 

This example implements the **Singleton pattern** for the `Logger` class. 

Remember, a Singleton ensures that **only one instance** of a given class 
exists throughout the program’s lifetime (or at least while it is in use).

In this implementation variant of the Singleton, we use a static local 
variable:

```cpp
shared_ptr<Logger> Logger::getInstance()
{
    static shared_ptr<Logger> instance(new Logger());
    return instance;
}
```

* The key is the use of a **static local variable** `instance`.

* In modern C++ (C++11 and onward), function-local static variables 
    are guaranteed to be **initialized exactly once** in a thread-safe manner.

* The first time `getInstance()` is called, instance is created 
    via `new Logger()`.

* On subsequent calls, the already-initialized `shared_ptr<Logger>` is 
    simply returned.

* Returning a `shared_ptr<Logger>` means that the pointer will manage 
    the lifetime of the `Logger` instance.
    As long as at least one `shared_ptr` to the logger exists, the logger 
    object will not be destroyed.

    The static variable `instance` itself remains in scope and is valid 
    until the program terminates. Therefore, the `logger` lives for the 
    entire duration of the program.

* The logger is constructed only if and when `getInstance()` is called 
    the first time. This is known as **lazy initialization**.    

* Since C++11, the initialization of a function-local static variable is 
    guaranteed to be thread-safe. This means that if multiple threads 
    call `getInstance()` simultaneously for the first time, the logger 
    will only be created once, in a safe manner.    

This implementation follows the **typical Singleton class structure**:

* The constructor `Logger()` of the singleton class is marked private 
    or protected to prevent creating additional instances outside of 
    the class itself.    

* The `getInstance()` method is typically static, which allows global-like 
    access while still maintaining a single instance.


By declaring a `static shared_ptr<Logger>` instance within the function, 
this implementation follows the **Meyers Singleton** style (function-local 
static) to ensure there is only one `Logger` in your application, and that 
creation is done in a thread-safe, on-demand manner. 

The use of `shared_ptr` gives precise control over object lifetime, though 
in a strict singleton scenario it typically remains alive for the duration 
of the program.

*Egon Teiniker, 2020-2025, GPL v3.0*
