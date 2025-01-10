# Smart Pointers 

Smart pointers are objects that **manage the lifetime of dynamically allocated 
(heap) memory**, ensuring that resources are properly released when they are no 
longer needed. 

They help prevent common memory management issues such as **memory leaks**, 
**dangling pointers**, and **double deletions** by automating memory management 
through the principles of **Resource Acquisition Is Initialization (RAII)**.

Smart pointers are part of the C++ Standard Library (since C++11) and are defined 
in the `<memory>` header. They encapsulate raw pointers and provide additional 
functionality to manage the memory they point to.

## Types of Smart Pointers

C++ provides several types of smart pointers, each with **distinct ownership 
semantics**:

* [**std::unique_ptr**](unique-pointer/): **Exclusive ownership**. 
    Only one `std::unique_ptr` can own a particular resource at any time.
    Cannot be copied, only moved.

* [**std::shared_ptr**](shared-pointer/): **Shared ownership**. 
    Multiple `std::shared_ptr` instances can own the same resource. 
    The resource is deleted when the last `std::shared_ptr` owning it is 
    destroyed or reset.

* **std::weak_ptr**: **Non-owning reference** to a resource managed by 
    `std::shared_ptr`. To **prevent cyclic references** that can lead to 
    memory leaks when using `std::shared_ptr`.

    Must be converted to `std::shared_ptr` to access the resource, 
    which involves checking if the resource still exists.

* **std::auto_ptr** (Deprecated): Exclusive ownership, similar to `std::unique_ptr`. 
    Deprecated in C++11 and removed in C++17. Replaced by `std::unique_ptr`.

## Best Practices

* Choose the right Smart Pointer:

    * Use `std::unique_ptr` when you need exclusive ownership.

    * Use `std::shared_ptr` when multiple owners are required.

    * Use `std::weak_ptr` to break cyclic dependencies with `std::shared_ptr`.

* Use `std::make_unique` and `std::make_shared` to create smart pointers. 
    These functions are exception-safe and can offer performance benefits.

* Avoid Mixing Raw and Smart Pointers: 
    
    * Prefer using smart pointers throughout your code to manage dynamic memory.
    
    * If you must use raw pointers, ensure that ownership semantics are clear 
        to prevent undefined behavior.


## References

* [YouTube: Modern C++: Upgrade Your Skills with Shared Pointers!](https://youtu.be/Tp5-f9YAzNk?si=vT_uuKNPBPj90sM5)

* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
    * Chapter 34. Memory and Resources

_Egon Teiniker, 2020-2024, GPL v3.0_