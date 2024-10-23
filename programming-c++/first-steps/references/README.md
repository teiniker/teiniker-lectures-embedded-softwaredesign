# References

Pointers are a crucial feature of C. They are the basis for **memory management 
in C** and allow **call-by-reference** semantics for parameter passing.

See also: [Memory Management in C](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/programming-c/c-advanced/memory-management)

Pointers are equally crucial to C++, but we have additional safety features 
available that defend against null dereferences and unintentional pointer 
reassignments. 

**References** are a major improvement to handling pointers. 
They’re similar to pointers, but with some key differences. 

Syntactically, references differ from pointers in two important ways. 
* We declare them with `&` rather than `*`.
* We interact with members using the dot operator `.` rather than the arrow operator `->`

_Example:_ Reference as parameter
```C++
struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};

void resistor_print(Resistor& r)
{
    printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);
}

Resistor r = {470, 1};
resistor_print(r);
```

Under the hood, **references are equivalent to pointers** because they’re also a 
zero-overhead abstraction. The **compiler produces similar code**.

However, at compile time, **references provide some safety over raw pointers** 
because, generally speaking, they cannot be null.

One other safety feature of references is that **they can’t be reseated**. 
In other words, once a reference is initialized, it can’t be changed to point 
to another memory address,


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2023, GPL v3.0*
