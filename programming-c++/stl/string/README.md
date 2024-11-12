# std::string 

In C++, `std::string` is part of the Standard Library and provides 
a way to handle sequences of characters as objects, making string 
manipulation far more convenient and safer than using C-style 
character arrays. 

The std::string class offers a rich set of functions to create, 
modify, and work with strings in a way that integrates with the 
C++ Standard Library.

The basic characteristics of `std::string` are:

* **Dynamic Size**: Unlike fixed-size character arrays, `std::string` 
    can grow or shrink as needed, thanks to its dynamic memory management.

* **Null-Termination**: Internally, `std::string` maintains a 
    null-terminated string (for compatibility with C-style functions), 
    though users do not have to manage this directly.

* **Templated**: `std::string` is a typedef for `std::basic_string<char>`, 
    allowing for similar templated strings with other character types, 
    like `std::wstring` for wide characters.

## Operations

* **Construction**l

    There are several ways to create an `std::string`:
    ```C++
    std::string s1 = "Hello, world!";  // From a C-string literal
    std::string s2("Hello, C++!");     // Direct initialization
    std::string s3(s1);                // Copy constructor
    std::string s4(s1, 0, 5);          // Substring constructor ("Hello")
    std::string s5(10, 'a');           // Repeating character ("aaaaaaaaaa")    
    ```

* **Concatenation**

    `std::string` supports the **+ operator** for concatenation:
    ```C++
    std::string s1 = "Hello, ";
    std::string s2 = "world!";
    std::string s3 = s1 + s2;  // "Hello, world!"
    ```

* **Accessing Characters**
    
    We can access characters using the **[]** or **at()** methods:
    ```C++
    char ch = s3[0];      // 'H'
    ch = s3.at(1);        // 'e'
    ```

* **Modifying Strings**

    * **Append**: Adds to the end of the string.
        ```C++
        s3.append(" Welcome!");  // "Hello, world! Welcome!"
        ```
    * **Insert**: Inserts at a specified position.
        ```C++
        s3.insert(7, "beautiful ");  // "Hello, beautiful world!"
        ```

    * **Replace**: Replaces a part of the string.
        ```C++
        s3.replace(7, 9, "awesome");  // "Hello, awesome world!"
        ```

    * **Erase**: Removes characters.
        ```C++
        s3.erase(7, 7);  // "Hello, world!"
        ```

* **Substring Extraction** 

    The `substr()` function extracts a portion of the string. 
    ```C++
    std::string sub = s3.substr(0, 5);  // "Hello"
    ```

* **Finding and Searching**

    * **find**: Finds the first occurrence of a substring or character.
    ```C++
    size_t pos = s3.find("world");  // Position of "world" (7)
    ```
    * **rfind**: Finds the last occurrence of a substring or character.
    * **find_first_of**: Finds the first occurrence of any of the specified characters.
    * **find_last_of**: Finds the last occurrence of any of the specified characters.

* **Comparing Strings** 

    We can use the comparison operators (`==`, `!=`, `<`, etc.) or 
    the `compare()` method.
    ```C++
    if (s1 == s2) 
    {
        std::cout << "Strings are equal.";
    }    
    ```

* **Size and Capacity**

    * **size()** or **length()**: Returns the number of characters
    ```C++
    size_t len = s3.size();
    ```
    * **empty()**: Checks if the string is empty.
    ```C++
    if (s3.empty()) 
    {
        std::cout << "String is empty.";
    }
    ```

    * **reserve()** and **capacity()**: Manage the reserved memory capacity 
        for potential expansions.

* **Conversion to C-style String**

    `c_str()` returns a pointer to a C-style, null-terminated character 
    array for compatibility with functions requiring char*.
    ```C++
    const char* cstr = s3.c_str();
    ```    

`std::string` is a flexible and powerful tool for handling text data, 
simplifying string management, and enhancing safety and ease of use 
compared to C-style strings.


## Examples and Exercises

* Example: [string-test](string-test/)



## References

* [C++ Reference: string](https://en.cppreference.com/w/cpp/string/basic_string)

*Egon Teiniker, 2020-2024, GPL v3.0*
