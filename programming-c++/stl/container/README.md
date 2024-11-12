# STL Containers

The Standard Template Library (STL) in C++ provides a set of commonly used 
data structures and algorithms. At its core, the STL offers containers, 
which are **objects that store collections of data**. 

These containers are templated, meaning they can hold data of any type, 
making them highly versatile and reusable. 

STL containers come in three main categories, each designed for specific 
data handling scenarios:

* **Sequence Containers**

    Sequence containers **store elements in a linear order**, allowing sequential 
    access and insertion. 

    * [std::vector](vector/): 
        A dynamic array that can grow and shrink in size. 
        Accessing elements by index is fast, but inserting elements anywhere 
        other than the end may be costly.


    * `std::deque`: A double-ended queue that allows efficient insertion 
        and deletion at both the front and the back. It provides random 
        access to elements, similar to a vector.

    * [std::list](list/): A doubly linked list that allows efficient insertion 
        and deletion at any position but does not support random access, 
        meaning accessing elements by index is slower.

    * `std::forward_list`: A singly linked list that supports efficient 
        insertion and deletion but only allows forward traversal (unlike 
        `std::list`, which supports bidirectional traversal).


* **Associative Containers**

    Associative containers **store elements in sorted order** and are generally 
    implemented as **balanced binary trees**. They allow fast retrieval of 
    elements based on keys, which are automatically sorted.

    * `std::set`: A container that stores unique elements in a specific order. 
        Provides fast lookup, insertion, and deletion.

    * `std::multiset`: Similar to `std::set` but allows duplicate elements.

    * `std::map`: Stores key-value pairs with unique keys in sorted order. 
        Each key is associated with a value, providing fast lookup, insertion, 
        and deletion based on keys.

    * `std::multimap`: Similar to `std::map` but allows duplicate keys.


* **Unordered Containers**
    
    Unordered containers **store elements without any specific ordering** but use 
    a **hash table** for fast access based on keys. They are faster than associative 
    containers for lookups on average but don’t guarantee any order.

    * `std::unordered_set`: Similar to std::set, but elements are not ordered, 
        and lookup is faster due to hashing.
    * `std::unordered_multiset`: Similar to std::multiset but unordered.
    * `std::unordered_map`: Similar to std::map, with key-value pairs but no ordering.
    * `std::unordered_multimap`: Similar to std::multimap, allowing multiple values for 
        a key, but without ordering.

* **Container Adapters**

    Adapters are wrappers around other containers that restrict certain functionalities 
    to provide a specific interface.

    * [std::stack](stack/): A **LIFO (Last In, First Out)** stack implemented using 
        `std::deque`, `std::vector`, or `std::list` by default.

    * [std::queue](queue/): A **FIFO (First In, First Out)** queue, implemented using 
        `std::deque` or `std::list`.

    * `std::priority_queue`: A priority queue where **elements are arranged based 
        on their priority**, typically implemented using a heap.

STL containers are a powerful part of C++, allowing developers to handle complex data 
efficiently with minimal effort. Each container has unique properties, making it suitable 
for specific use cases.

The choice of container depends on:
* The type of data you are working with.
* The performance characteristics you need (e.g., fast insertion, random access).
* Whether duplicates or ordered storage are important.


## References


*Egon Teiniker, 2020-2024, GPL v3.0*
