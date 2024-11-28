# Inheritance 

Inheritance is a fundamental object-oriented programming (OOP) concept that 
allows a class (known as a **derived class** or child class or **sub class**) 
to acquire properties and behaviors (i.e., data members and member functions) 
from another class (known as a **base class** or parent class or **super class**). 

Inheritance promotes **code reusability**, establishes a natural hierarchy 
between classes, and facilitates **polymorphism**.

The C++ language features support building new classes from existing ones: 

* **Implementation inheritance**: to save implementation effort by sharing 
    facilities provided by a base class 
    
* **Interface inheritance**: to allow different derived classes to be used 
    interchangeably through the interface provided by a common base class 
    Interface inheritance is often referred to as run-time polymorphism (or 
    dynamic polymorphism).


## Class Members

A member of a derived class can use the **public** and **protected** members 
of a base class as if they were declared in the derived class itself.

**A derived class cannot access private members of a base class**.


## Constructors and Destructors

Constructors and destructors are as essential: 

* When a derived class object is created, the **base class constructor is called first**, 
    followed by the derived class constructor.

* **Destructors are called in reverse order**: derived class destructor is called first, 
    followed by the base class destructor.


## Types of Inheritance

Determine how members of the base class are accessed in the derived class.
* **Public Inheritance**: Public and protected members of the base class retain 
    their access levels in the derived class.

* **Protected Inheritance**: Public and protected members of the base class become 
    protected in the derived class.

* **Private Inheritance**: Public and protected members of the base class become 
    private in the derived class.


_Example:_ Public inheritance of classes

```C++  
// Base class
class Entity 
{
	private:
		int _id; 
 
	public:
		Entity(int id);
		
		int id(void);
 };
```

```C++ 
// Derived class
class Product : public Entity
{
	private:
		std::string _description; 
		long _price;
 
	public:
		Product(int id, const std::string& description, long price); 

		std::string description(void);
		long price(void);
};
```

```C++
// Constructor implementation
Product::Product(int id, const string& description, long price) 
	: Entity(id), _description{description}, _price{price}
{
}
```

The **member initialization list** initializes the base class and the member 
variables of the derived class before the body of the constructor is executed.

* `Entity(id)`:
    **Calls the constructor of the base class** `Entity` with id as an argument.
    This ensures that the base class is initialized properly before any derived 
    class-specific initialization occurs.

* `_description{description}` and `_price{price}`:
    **Initializes member variables** with the value of the parameter list.


## Virtual Functions

In the context of inheritance in C++, virtual functions are **member functions 
in a base class that can be overridden** in a derived class to provide specific 
behavior for objects of the derived class. 

**Virtual functions enable polymorphism**, allowing a program to decide at runtime 
which function to call, depending on the type of the object being referred to, 
rather than the type of the pointer or reference used to refer to the object.

Key Characteristics of Virtual Functions:

* **Declared with the virtual Keyword**: A function is made virtual in the base 
    class by prefixing it with the `virtual` keyword.
    
* **Overriding**: A derived class can provide its own implementation of a virtual 
    function, overriding the behavior of the base class function.

* **Polymorphism**: Virtual functions support runtime polymorphism (or dynamic dispatch) 
    by determining the actual type of the object being pointed to and calling the 
    corresponding function.

* **Function Resolution at Runtime**: Virtual functions use a mechanism called the 
    **virtual table** (vtable), which stores pointers to virtual functions for the class.

* **Base Class Pointer or Reference**: When a base class pointer or reference points 
    to a derived class object, the derived class's version of the function is called.

* **Virtual Destructors**: If a class has virtual functions, its destructor should 
    also be declared virtual to ensure proper cleanup of derived class objects.



## References  

## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 20: Derived Classes

*Egon Teiniker, 2020-2024, GPL v3.0*