# Classes and Objects 

Classes are the central feature of an **object oriented language**. 

* A class is a **user-defined type**.

* A class consists of a **set of members**. The most common kinds of members are data members and member functions.

* A **class is a namespace** containing its members.

* The **public members provide the class’s interface** and the **private members provide implementation details**.

* A **struct** is a class where **members are by default public**.

* Members are accessed using **. (dot) for objects** and **–> (arrow) for pointers**.

* Member functions can define the meaning of **initialization (creation)**, **copy**, **move**, and **cleanup (destruction)**.

* **Operators**, such as `+`, `!`, and `[]`, can be defined for a class.


## Class Declaration

In C++ a **class** is a user-defined type that has **attributes** 
(data members) and **methods** (member functions). 

_Example_: C++ class declaration (`date.h`)
```C++
class Date 
{
    private:
        int _day;
        int _month;
        int _year;

    public:
        Date(int d, int m, int y);  // Constructor   
        ~Date();                    // Destructor

        // Getter and Setter Methods
        int Date::day() const { return _day; }          // inline function
        void Date::day(const int day) { _day = day; }   // inline function

        int month() const; 
        void month(const int m);
        
        int year() const;
        void year(const int y);

        // Operations
        bool isLeapYear();
};
``` 

### Access Control

The **public** keyword is an access specifier. It specifies the access
level of the members of the class. The public members of a class are 
**accessible from outside** the class.

The **private** keyword is also an access specifier. The private members 
of a class are **only accessible within the class**. They are not accessible 
from outside the class.

All **members of a class** (attributes and methods) are **private per default**.


### Constructor

**Constructors** are special class members which are called by the compiler 
every time an object of that class is instantiated. Constructors have the 
**same name as the class**.
 
There are three different types of constructurs in C++:

* **Default Constructors:** 
    The default constructor is the constructor which doesn’t take any 
    argument (it has no parameters).
    If we do not define any constructor explicitly, the compiler will 
    automatically provide a default constructor implicitly.    

    _Example_: `Date()`
    
* **Parameterized Constrcutors:**
    It is possible to pass arguments to constructors. These arguments 
    help initialize an object when it is created. Note that constructors 
    also can be overloaded.        

    _Example_: `Date(int d, int m, int y)`

* **Copy Constructors:**
    A copy constructor is a member function which initializes an object 
    using another object of the same class. 
    If we don’t define our own copy constructor, the C++ compiler 
    creates a default copy constructor for each class which does a 
    member-wise copy between objects (**shallow copy**) . 
    We need to define our own copy constructor only if an object has 
    pointers or any runtime allocation of the resource like file handle, 
    a network connection etc. (**deep copy**).        
    
    _Example_: `Date(const Date &date)`
    
Like functions, **constructors can be overloaded** if they differ in their 
parameter lists.    

**Default arguments** are also allowed for constructors.


### Destructor
Destructor is another special member function that is called when the 
**scope of the object ends** or the **delete operator** is called.

Destructors have same name as the class preceded by a tilde `~`, 
**don’t take any argument, and don’t return anything**.
Note that there can only be one destructor in a class.

```C++
    ~Date();
```     

If we do not write our own destructor in class, compiler creates a 
**default destructor** for us. The default destructor works fine unless 
we have dynamically allocated memory or pointer in class. 
When a class contains a pointer to memory allocated in class, we should 
write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.


### Getter and Setter Methods

Getter and setter methods are fundamental components in object-oriented 
programming (OOP). They provide controlled access to an object's internal 
data (its attributes or member variables) while maintaining the principles 
of **encapsulation** and **data hiding**.

The **const keyword** can be used in various contexts in C++, but in the 
context of member functions, it serves a specific purpose related to
const-correctness. 

**Const-correctness** ensures that functions that are not supposed to modify 
the state of an object are explicitly marked, enhancing code safety and 
readability.

* `int Date::day() const`: Indicates that the `day()` member function is 
    a **constant member function**. Specifically, it promises not to modify 
    any member variables of the `Date` object (unless those members are marked 
    as mutable).

* `void Date::day(const int day)`: This marks the parameter day as a constant 
    within the function, meaning that within the function body, **we cannot 
    modify the value of `day`**.


## Class Implementation

### Header vs. Source Files

We **separate the declaration and the implementation of methods** (header 
and source file).

_Example_: C++ class implementation (`date.cpp`)
```C++
Date::Date(int day, int month, int year) 
    : _day{day}, _month{month}, _year{year}   
{
}

Date::~Date() 
{
}

int Date::month() const { return _month; }
void Date::month(const int month) { _month = month; }

int Date::year() const { return _year; }
void Date::year(const int year) { _year = year; }

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
```

When we implement methods outside a class declaration we use the 
**scope resolution :: operator**.

All the member functions defined inside the class declaration are 
by default **inline**, but we can also make any non-class function 
inline by using keyword `inline` with them. 

Inline functions are actual functions, which are copied everywhere 
during compilation, like pre-processor macro, so the overhead of 
function calling is reduced.


## Objects (Class Instances)

At runtime, programs consist of instances of classes, the so-called 
objects. The functionality of an application is created through the 
interaction of these objects.

### Objects on the Stack

To create **Objects** (instances of a class), we define variables of this 
type. Note that the methods can be called directly on these instances using 
the **dot notation**.

```C++
TEST(DateTest, Constructor) 
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth

    EXPECT_EQ(23, birthday.day());
    EXPECT_EQ(6, birthday.month());
    EXPECT_EQ(1912, birthday.year());
}
``` 
These objects are created on the stack and go out of scope at the end of 
a method or function.


### Objects on the Heap

To create objects on the heap we use the **new** operator. 
To delete objects from the heap, we use the **delete operator**. 

Note that **all objects on the heap must be deleted manually** using delete.

```C++
TEST(DateTest, ConstructorWithNew) 
{
    Date* birthday = new Date(23, 6, 1912);

    EXPECT_EQ(23, birthday->day());
    EXPECT_EQ(6, birthday->month());
    EXPECT_EQ(1912, birthday->year());

    delete birthday;
}
``` 

The `new` operator returns a pointer to the created object, thus, 
the members of an object are accessed with the **arrow operator**.



## Examples and Exercises

The following examples and exercises are intended to further clarify the concepts surrounding classes:

* **Classes and Objects** 
    * Example: [date](date/)
    * Example: [book](book/)
    * Exercise: [resistor](resistor-exercise/) ([Model Solution](resistor/))
    * Exercise: [can-message](can-message-exercise/) ([Model Solution](can-message/))

* **Constructor and Destructor**
    * Exercise: [eeprom](eeprom-exercise/) ([Model Solution](eeprom/))
    * Exercise: [lcd](lcd-exercise/) ([Model Solution](lcd/))

* **Static Members**
    * Example: [integer-sequence](integer-sequence/)

* **Directed Associations**
    * Example: [order-directed](order-directed/)
    * Exercise: [user-mail-directed](user-mail-directed-exercise/) ([Model Solution](user-mail-directed/))

* **Bidirectional Associations**
    * Example: [directory-bidirectional](directory-bidirectional/)
    * Exercise: [user-mail-bidirectional](user-mail-bidirectional-exercise//) ([Model Solution](user-mail-bidirectional/))

* **Composition**
    * Example: [event](event/)


## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 16: Classes
* Chapter 17: Construction, Cleanup, Copy, and Move 

[C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)

[Constructors in C++](https://www.geeksforgeeks.org/constructors-c/)

[Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)

[Destructors in C++](https://www.geeksforgeeks.org/destructors-c/)

*Egon Teiniker, 2020-2024, GPL v3.0*
