# Operator Overloading

Operator overloading allows C++ operators to have user-defined 
meanings on custom types. Essentially, it **provides a way to specify 
how operators behave when applied to objects of classes we define**.

Benefits of using operator overloading:

* **Intuitiveness**: Makes the use of user-defined types as natural 
    as built-in types.

* **Readability**: Enhances code clarity by allowing operators to 
    express operations succinctly.

* **Maintainability**: Facilitates cleaner and more maintainable code 
    by avoiding verbose function calls.


## Types of Operators

C++ allows the overloading of most operators, but some have restrictions. 
Operators can be categorized based on their functionality.

* **Assignment Operators**

    * **Basic Assignment**: `=`

    * **Compound Assignments**: `+=`, `-=`, `*=`, `/=`, `%=`, etc.

* **Arithmetic Operators**

    * **Unary Operators**: `-` (negation), `++`, `--`

    * **Binary Operators**: `+`, `-`, `*`, `/`, `%`

* **Relational and Logical Operators**
    
    * **Relational**: `==`, `!=`, `<`, `>`, `<=`, `>=`
    
    * **Logical**: `&&`, `||`, `!` 
        
* **Subscript Operator**
    
    * **Access elements** like in arrays: `[]` 

* **Stream Insertion and Extraction Operators**

    * **Insertion**: `<<`

    * **Extraction**: `>>`

* **Function Call Operator**
 
    * Makes an **object callable** like a function: `()` 

* **Pointer Operators**

    * **Dereferencing**: `*`

    * **Member access**: `->`


## Friend Functions

Operators can be implemented as member or friend functions.

A friend function is a **non-member function** that has been granted special 
**access privileges to the private and protected members of a class**. 

Unlike member functions, friend functions are not invoked on objects of the 
class using the dot `.` or arrow `->` operators. Instead, they operate
independently but can still manipulate the class's internal state directly.

Key characteristics of friend functions:

* **Non-Member**: Friend functions are not part of the class's public interface 
    and do not have a this pointer.

* **Access Privileges**: They can access private and protected members of the 
    class.

* **Declared with friend**: To be a friend, the function must be explicitly 
    declared within the class using the `friend` keyword.

* **Not Inherited**: Friend status is not inherited by derived classes.



## How to Overload Operators in C++

Operators can be overloaded by defining a special function associated 
with the operator (**operator functions**). 

There are two primary ways to overload operators:

* **Member Function Overloading**: Implemented within the class as 
    a member function.

    _Syntax:_ `ReturnType operatorOp(Parameters);`

    _Example:_ `Complex` overloads the `+` operator
    ```C++
    class Complex 
    {
        public:
            //...
            Complex operator +(const Complex& c)
            {
                Complex result(_re + c._re, _im + c._im);
                return result;
            }
    };
    ```

    Operators that must be member functions:

    * **Assignment Operators**: `=`, `+=`, `-=`, etc.
    * **Subscript Operator**: `[]`
    * **Member Access Operators**: `->` 
    * **Function Call Operator**: `()`
 

* **Non-Member (Friend) Function Overloading**: Implemented outside 
    the class, often as a friend to access private members.

    _Syntax:_ `ReturnType operatorOp(const ClassName& lhs, const ClassName& rhs);`

    _Example:_  Overloads the `==` operator for `Complex`
    ```C++
    class Complex 
    {
        //...
        friend bool operator== (const Complex &c1, const Complex &c2);
    };

    // Friend function
    bool operator== (const Complex &c1, const Complex &c2)
    {
        return (c1._re == c2._re && c1._im == c2._im);
    }
    ```

    Operators that can only be non-member functions:
    * **Stream Insertion and Extraction Operators**: `<<`, `>>`
    * **Arithmetic Operators with Commutative Behavior**: If we 
        want to allow `int + Complex` as well as `Complex + int`, 
        we might need non-member overloads.


## Best Practices for Operator Overloading

* **Follow Operator Semantics**: Overloaded operators should behave 
    in a manner consistent with their built-in counterparts to avoid 
    confusion.

* **Maintain Consistency and Predictability**: Ensure that the 
    overloaded operators are intuitive and their usage aligns with 
    common expectations.

* **Avoid Overloading for Primitive Types**: Overloading operators for 
    built-in types can lead to ambiguous or undefined behavior. 
    Stick to user-defined types.

* **Use Member Functions vs. Non-Member Functions Appropriately**:

    * **Member Functions**: Suitable for operators that modify the object 
        or require access to its internal state.

        _Example_: `operator+`, `operator-`

    * **Non-Member (Friend) Functions**: Useful for symmetric operators 
        where both operands are of different types.

    _Example_: `operator==`, `operator<<`

* **Return Types Should Be Appropriate**:

    * **Binary Operators**: Typically **return a new object** 
    
        _Example:_ `Complex operator+(const Complex& other) const;`

    * **Assignment Operators**: Should **return a reference 
        to the current object** to allow chaining.
        
        _Example:_ `Complex& operator=(const Complex& other);`



## Examples and Exercises

* **Assignment Operator**:
    * [Introduction](operator-assignment/README.md)
    * Demo: [mail](operator-assignment/mail/)
    * Demo: [user-mail](operator-assignment/user-mail/)

* **Arithmetic Operators**:
    * Demo: [complex-number](operator-arithmetic/complex-number/)
    * Exercise: [counter](operator-arithmetic/counter-exercise/) 
        ([Model Solution](operator-arithmetic/counter/))

* **Relational and Logical Operators**:
    * Demo: [range](operator-relational/range/)

* **Subscript Operators**
    * Exercise: [eeprom](operator-subscript/eeprom-exercise/) 
        ([Model Solution](operator-subscript/eeprom))

Also review the **operators** of the following **standard library classes**:

* [std::string](https://en.cppreference.com/w/cpp/string/basic_string)

* [std::vector](https://en.cppreference.com/w/cpp/container/vector)


## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 18: Operator Overloading

* [Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-c/)


*Egon Teiniker, 2020-2024, GPL v3.0*