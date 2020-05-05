# Pointers vs. References

**Pointers**: A pointer is a variable that holds memory address of another variable. 
A pointer needs to be dereferenced with * operator to access the memory location it points to.

**References**: A reference variable is an alias, that is, another name for an already existing variable. 
A reference, like a pointer, is also implemented by storing the address of an object.


## Difference in Reference Variables and Pointer Variables:

* A pointer can be re-assigned while reference cannot, and must be assigned at initialization only.
* Pointer can be assigned NULL directly, whereas reference cannot.
* Pointers can iterate over an array, we can use ++ to go to the next item that a pointer is pointing to.
* A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
* A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a reference uses a ‘.'(dot operator)
* A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.


## When to use What

Use references:
* In function parameters and return types.
	
Use pointers:
* Use pointers if pointer arithmetic or passing NULL-pointer is needed. For example for arrays (Note that array access is implemented using pointer arithmetic).
* To implement data structures like linked list, tree, etc and their algorithms because to point different cell, we have to use the concept of pointers.

Use references when you can, and pointers when you have to. 

References are most useful in a class’s public interface. 
References typically appear on the skin of an object, and pointers on the inside.

The exception is where a function’s parameter or return value needs a “sentinel” reference — a reference that does not refer to an object. 
This is usually best done by returning/taking a pointer, and giving the NULL pointer this special significance (references must always alias 
objects, not a dereferenced null pointer).

The performances are exactly the same, as references are implemented internally as pointers. 

	
## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 7: Pointers, Arrays, and References

[Pointers vs References in C++](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)

[Passing by pointer Vs Passing by Reference in C++](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/)

*Egon Teiniker, 2020, GPL v3.0*
