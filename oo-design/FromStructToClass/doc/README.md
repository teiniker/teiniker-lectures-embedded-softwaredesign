# From Struct to Class

## Using C Structures

Given a structure which can be modified with different functions.

```C
typedef struct ComplexNumber_
{
    double re;
    double im;
    
} ComplexNumber;

void complex_init(ComplexNumber *self, double re, double im);
void complex_add(ComplexNumber *self, ComplexNumber c);
void complex_sub(ComplexNumber *self, ComplexNumber c);
```
We can define multiple instances of this structure and apply the same 
functions to each of these instances. We simply pass the pointer of the 
particular instance to a function.

```C
ComplexNumber number = {1.0, 2.0};
ComplexNumber c = {3.0, 4.0};

complex_add(&number,c);
```
This is a common implementation technique for data structures.
Real objects (e.g. user) can also be displayed in this form.
 
We cannot just create this structure on the stack. 
With the help of the functions **malloc()** and **free()** we can 
manage any number of *ComplexNumber* instances on the heap.
 
```C
ComplexNumber *c_ptr = (ComplexNumber *)malloc(sizeof(ComplexNumber)); 
complex_init(c_ptr, 1.0, 2.0);

//...

free(c_ptr);
``` 

This procedure also has **disadvantages**:
* The data in the Structure *ComplexNumber* is always accessible (public) 
and can be changed or read out at any time.
* It is easy to forget to call the *complex_init()* function so that the 
structure has not been initialized.
* Each function must define the pointer to the structure as the first 
parameter.

In C ++, attempts have been made to eliminate these disadvantages by 
introducing classes.


## Using C++ Classes

Classes are the central feature of an object-oriented language. 

### Defining a Class

In C++ a **class** is a user-defined type that has **attributes** (data members) and 
**methods** (member functions). Both of them can be visible (public) or invisible
(private) to the code that uses instances of that class.

```C++
class ComplexNumber
{
    private: // optional
        double re_;
        double im_;
 
    public:
        double real() 
        {
            return re_;
        }
        void real(double re)
        {
            re_ = re;
        }
        
        double imag()
        {
            return im_;
        }
        void imag(double im)
        {
            im_ = im;
        }
        
        void add(ComplexNumber c);
        void sub(ComplexNumber c);
};        

void ComplexNumber::add(ComplexNumber c)
{
    re_ += c.real();
    im_ += c.imag();
}

void ComplexNumber::sub(ComplexNumber c)
{
    re_ -= c.real();
    im_ -= c.imag();
}
``` 
All members of a class (attributes and methods) are private 
per default.

As shown for the metods **add()** and **sub()**, we can also separate the 
declaration and the implementation of methods (header and source file).
When we implement methods outside a class we use the scope **resolution :: operator**.

All the member functions defined inside the class definition are by 
default **inline**, but we can also make any non-class function inline 
by using keyword inline with them. 
Inline functions are actual functions, which are copied everywhere 
during compilation, like pre-processor macro, so the overhead of function 
calling is reduced.


To create **Objects** (instances of a class), we define variables of this type. 
Note that the methods can be called directly on these instances using the 
dot notation.

```C++
ComplexNumber number(1.0, 2.0); 
ComplexNumber c(3.0, 4.0);

number.add(c);
``` 
These objects are also created on the stack and go out of scope 
at the end of a method or function.

To objects on the heap we use the **new** operator. 
To delete objects from the heap, use the **delete operator**. 
Note that all objects on the heap must be deleted manually using delete.
```C++
ComplexNumber *c_ptr = new ComplexNumber(1.0, 2.0); 

//...

delete c_ptr;
``` 
The new operator returns a pointer to the created object, thus, the 
members of an object are accessed with the **arrow operator**, for example: 
**c_ptr->real()**.


### Constructor

**Constructors** are special class members which are called by the compiler 
every time an object of that class is instantiated. Constructors have the 
same name as the class and may be defined inside or outside the class 
definition.

```C++
// Default constructor
ComplexNumber() : re_{0}, im_{0}
{
}

// Parametrized constructors
ComplexNumber(double re, double im) : re_{re}, im_{im}
{
}
``` 
There are three different types of constructurs in C++:
* **Default Constructors:** 
    The default constructor is the constructor which doesn’t take any 
    argument (it has no parameters).
    If we do not define any constructor explicitly, the compiler will 
    automatically provide a default constructor implicitly.    
    Example: ComplexNumber()
    
* **Parameterized Constrcutors:**
    It is possible to pass arguments to constructors. These arguments 
    help initialize an object when it is created. Note that constructors 
    also can be overloaded.        
    Example: ComplexNumber(double re, double im)

* **Copy Constructors:**
    A copy constructor is a member function which initializes an object 
    using another object of the same class. 
    If we don’t define our own copy constructor, the C++ compiler 
    creates a default copy constructor for each class which does a 
    member-wise copy between objects (**shallow copy**) . 
    We need to define our own copy constructor only if an object has 
    pointers or any runtime allocation of the resource like file handle, 
    a network connection etc. (**deep copy**).        
    Example: ComplexNumber(const ComplexNumber &number)
    
    
### Destructor
Destructor is another special member function that is called when the 
scope of the object ends or the delete operator is called.

Destructors have same name as the class preceded by a tilde (~), don’t 
take any argument, and don’t return anything.
Note that there can only be one destructor in a class.

```C++
~ComplexNumber() 
{            
    // Called before an object will be removed.
}
```     

If we do not write our own destructor in class, compiler creates a 
**default destructor** for us. The default destructor works fine unless 
we have dynamically allocated memory or pointer in class. 
When a class contains a pointer to memory allocated in class, we should 
write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.

    

## References

[C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)
[Constructors in C++](https://www.geeksforgeeks.org/constructors-c/)
[Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)
[Destructors in C++](https://www.geeksforgeeks.org/destructors-c/)

*Egon Teiniker, 2020, GPL v3.0*
