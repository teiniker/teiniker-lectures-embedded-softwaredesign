# Exception Handling

Exception handling in C++ is a mechanism that allows a program to 
detect and respond to anomalous or exceptional conditions—such 
as runtime errors without crashing. 

It provides a **structured way to handle errors**, making the code more 
robust and easier to maintain.


## Introduction

A C++ exception is a response to an exceptional circumstance that arises 
while a program is running.

Exceptions provide a way to transfer control from one part of a program to another. 
C++ exception handling is built upon three keywords: try, catch, and throw:

* **throw** − A program throws an exception when a problem shows up. This is done using a throw keyword.

* **catch** − A program catches an exception with an exception handler at the place in a program where 
	you want to handle the problem. The catch keyword indicates the catching of an exception.

* **try** − A try block identifies a block of code for which particular exceptions will be activated. 
	It's followed by one or more catch blocks.


We can list down multiple catch statements to catch different type of exceptions in case our try block 
raises more than one exception in different situations.

```C++
	try 
	{
		// protected code
	} 
	catch( ExceptionType1 e ) 
	{
		// catch block
	} 
	catch( ExceptionType2 e ) 
	{
		// catch block
	} 
	catch( ExceptionTypeN e ) 
	{
		// catch block
	}
```		


## Standard Exceptions

C++ provides a list of [standard exceptions](https://en.cppreference.com/w/cpp/error/exception) 
defined in <stdexcept> which we can use in our programs.

* `std::exception`: An exception and parent class of all the standard C++ exceptions.

	* `std::bad_alloc`: This can be thrown by new.

	* `std::bad_cast`: This can be thrown by dynamic_cast.

	* `std::bad_typeid`: This can be thrown by typeid.

	* `std::bad_exception`: This is useful device to handle unexpected exceptions in a C++ program.

	* `std::logic_failure`: An exception that theoretically can be detected by reading the code.
		* `std::domain_error`: This is an exception thrown when a mathematically invalid domain is used.
		* `std::invalid_argument`: This is thrown due to invalid arguments.
		* `std::length_error`: This is thrown when a too big `std::string` is created.
		* `std::out_of_range`: This can be thrown by the 'at' method, for example a `std::vector` and `std::bitset<>::operator[]()`

	* `std::runtime_error`: An exception that theoretically cannot be detected by reading the code.
		* `std::overflow_error`: This is thrown if a mathematical overflow occurs.
		* `std::range_error`: This is occurred when you try to store a value which is out of range.
		* `std::underflow_error`: This is thrown if a mathematical underflow occurs.
	
All exceptions generated by the standard library inherit from 
[std::exception](http://www.cplusplus.com/reference/exception/exception/).
Therefore, all standard exceptions can be caught by catching this type by reference.

```C++
class exception {
public:
	exception () noexcept;
	exception (const exception&) noexcept;
	exception& operator= (const exception&) noexcept;
	virtual ~exception();
	virtual const char* what() const noexcept;
}
```

By declaring a function or a method as **noexcept**, we specify that these 
does not throw an exception and if they throw, we do not care and let the 
program just crash.
			
The `noexcept` specification is equivalent to the `noexcept(true)` specification. 
**throw()** is equivalent to `noexcept(true)` but was deprecated with C++11 and 
will be removed with C++20. 

In contrast, `noexcept(false)` means that the function may throw an exception. 
The `noexcept` specification is part of the function type but can not be used 
for function overloading. 

			
## Defining Exceptions

We can define our own exceptions by inheriting and overriding exception class functionality. 

The simplest way of defining an exception is to define a class specifically for 
a kind of error and throw that.

```C++
	class RangeError 
	{
	};

	void f(int n)
	{
	 if (n<0 || max<n) 
	 	throw RangeError;
	  //...
	}
```

An exception can carry information about the error it represents. 
Its type represents the kind of error, and whatever data it holds represents the 
particular occurrence of that error.

```C++
class FileNotFound : public std::exception 
{
	private:
		std::string _cause;
		
	public:
		FileNotFound(const std::string& cause) : _cause{cause} {}
		
		const char* what() const noexcept
		{
			return _cause.c_str();
		}
};
```

**what()** is a public method provided by **exception** class and it has been 
overridden by all the child exception classes. 
This returns the cause of an exception.


## Throwing Exceptions

Exceptions can be thrown anywhere within a code block using throw statement. 
The operand of the throw statement determines a type for the exception and can be any expression and 
the type of the result of the expression determines the type of exception thrown.

```C++
	if(id < 0)
		throw invalid_argument("Invalid id!");
```


## Catching Exceptions

The catch block following the try block catches any exception. You can specify what 
type of exception you want to catch and this is determined by the exception declaration 
that appears in parentheses following the keyword catch.

```C++
	try 
	{
	   // protected code
	} 
	catch( ExceptionName e ) 
	{
	  // code to handle ExceptionName exception
	}
```


## Examples and Exercises

* Throwing Exceptions:
	* Example: [input-validation](input-validation/)

* Catching Exceptions:
	* Example: [data-service](data-service/)  
	* Exercise: [controller](controller-exercise/) ([Model Solution](controller/))


## References

* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
	* Chapter 13: Exception Handling

* [C++ Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)


_Egon Teiniker, 2020-2024, GPL v3.0_