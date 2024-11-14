# std::vector

In C++, `std::vector` is a **dynamic array** provided by the Standard 
Template Library (STL). It is one of the most commonly used sequence 
containers, offering a flexible, efficient way to store and manage 
collections of elements. 

Unlike C-style arrays, `std::vector` **can grow or shrink in size dynamically**, 
allowing us to add or remove elements as needed without manual memory management.

The basic characteristics of `std::vector` are:
* **Dynamic Sizing**: `std::vector` can automatically resize itself when 
    elements are added or removed, unlike fixed-size arrays.
* **Random Access**: You can access elements in constant time O(1) using 
    an index, just like with an array.
* **Contiguous Memory**: `std::vector` stores elements in a contiguous block 
    of memory, making it cache-friendly and compatible with C-style arrays 
    when needed.
* **Automatic Memory Management**: `std::vector` manages its memory allocation, 
    so you don't need to manually allocate or deallocate memory.

## Operations

* **Construction**
    We can create and initialize a `std::vector` in several ways:
    ```C++
    std::vector<int> v1;                   // Empty vector of ints
    std::vector<int> v2(10);               // Vector of 10 ints (default initialized to 0)
    std::vector<int> v3(10, 42);           // Vector of 10 ints, each initialized to 42
    std::vector<int> v4 = {1, 2, 3, 4, 5}; // Vector initialized with a list of values
    std::vector<int> v5(v4);               // Copy constructor    
    ```

* **Adding Elements**
    * **push_back**: Adds an element to the end of the vector. This operation 
        may trigger a reallocation if the vector's capacity is exceeded.
        ```C++
        v1.push_back(10);  // Adds 10 to the end of v1
        ```
    * **emplace_back**: Constructs an element in place at the end, avoiding unnecessary copying.
        ```C++
        v1.emplace_back(20);  // More efficient than push_back for complex objects
        ```
* **Removing Elements**
    * **pop_back()**: Removes the last element in the vector.
        ```C++
        v1.pop_back();
        ```
    * **erase()**: Removes elements at a specified position or range.
        ```C++
        v1.erase(v1.begin() + 2);      // Removes the element at index 2
        v1.erase(v1.begin(), v1.end()); // Removes all elements
        ```
    * **clear()**: Removes all elements, making the vector empty.
        ```C++
        v1.clear();
        ```

* **Accessing Elements**
    * **operator[]**: Provides direct access to an element by index (no bounds checking).
        ```C++
        int value = v4[2];  // Accesses the element at index 2
        ```

    * **at()**: Similar to `[]`, but performs bounds checking and throws an exception if 
        the index is out of range.
        ```C++
        int value = v4.at(2);  // Throws an exception if index is invalid
        ```
    * **front()** and **back()**: Access the first and last elements, respectively.
        ```C++
        int first = v4.front();
        int last = v4.back();
        ```

* **Capacity Management**

    * **size()**: Returns the number of elements in the vector
        ```C++
        site_t len = v4.size();
        ```

    * **capacity()**: Returns the amount of storage allocated for the vector, 
        which may be greater than its current size.

    * **empty()**: Checks if the vector is empty.
        ```C++
        if (v4.empty()) 
        {
            std::cout << "Vector is empty";
        }
        ```
    * **reserve()**: Requests a change in the capacity of the vector, useful for 
        optimizing memory allocation when you know the vector's expected size.
        ```C++
        v4.reserve(100);  // Reserves space for at least 100 elements
        ```
    
    * **shrink_to_fit()**: Reduces capacity to match the current size, freeing 
        unused memory.
        ```C++
        v4.shrink_to_fit();
        ```

* **Iterating through Elements**

    We can use iterators or range-based for loops to iterate through a `std::vector`:
    ```C++
    for (int i : v4) 
    {
        std::cout << i << " ";
    }
    ```

    ```C++
    for (std::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    ```

`std::vector` is a powerful and flexible container that combines the convenience 
of dynamic sizing with efficient access and management of memory, making it a 
cornerstone of C++ STL containers.

## Examples and Exercises

* Example: [vector-test](vector-test/)


## References

* [C++ Reference: vector](https://en.cppreference.com/w/cpp/container/vector)


*Egon Teiniker, 2020-2024, GPL v3.0*
