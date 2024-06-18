# Unique Pointer

Manages the storage of a pointer, providing a **limited garbage-collection facility**, 
with little to no overhead over built-in pointers.

These objects have the ability of taking ownership of a pointer: once they 
take ownership they manage the pointed object by becoming responsible for 
its deletion at some point.

unique_ptr objects **automatically delete** the object they manage as soon as 
they themselves are destroyed, or as soon as their value changes either 
by an assignment operation or by an explicit call to unique_ptr::reset.

A unique_ptr object has two components:
* A **stored pointer**: the pointer to the object it manages. This is set 
	on construction, can be altered by an assignment operation or by calling 
	member reset, and can be individually accessed for reading using members 
	get or release.

* A **stored deleter**: a callable object that takes an argument of the same 
	type as the stored pointer and is called to delete the managed object. 
	It is set on construction, can be altered by an assignment operation, 
	and can be individually accessed using member get_deleter.

unique_ptr objects replicate a limited pointer functionality by providing 
access to its managed object through operators * and -> (for individual 
objects), or operator [] (for array objects). 

For safety reasons, they **do not support pointer arithmetics**, and only support 
move assignment (disabling copy assignments).

## Example

```C++
TEST(MailTestGroup, UniquePointerTest)
{
	// Setup
    std::unique_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());

	// Teardown
    // mail goes out of scope and deletes the Mail instance.
}
```

## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 34.3: Resource Management Pointers

[std::unique_ptr](http://www.cplusplus.com/reference/memory/unique_ptr/)
[C++11 Smart Pointer – Part 6 : unique_ptr<> Tutorial and Examples](https://thispointer.com/c11-unique_ptr-tutorial-and-examples/)

*Egon Teiniker, 2020, GPL v3.0*
