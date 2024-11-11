# Operator Overloading (Binary Operators)

The meaning of an operator is always same for variable of basic types like: int, float, double etc. 
For example: To add two integers, + operator is used.

For user-defined types (classes), we can redefine the way operator works.		

This feature in C++ programming that allows programmer to redefine the meaning of an operator 
(when they operate on class objects) is known as **operator overloading**.

To overload an operator, a special operator function is defined inside the class as:

```C++
class className
{
    ... .. ...
    public
       returnType operator symbol (arguments)
       {
           ... .. ...
       } 
    ... .. ...
};
```
To overload an operator, we need:
* **returnType** is the return type of the function.
* The returnType of the function is followed by **operator keyword**.
* **Symbol** is the operator symbol you want to overload. Like: +, <, -, ++
* we can pass **arguments** to the operator function in similar way as functions.

*Example:* Complex number overloads the + operator
```C++
class Complex 
{
	public:
		...
		Complex operator +(const Complex& c)
		{
			Complex result(real_ + c.real_, imag_ + c.imag_);
			return result;
		}
		...			 
 };
```

Things to remember
* Operator overloading allows you to redefine the way operator works for user-defined types only (class, structure). 
  It cannot be used for built-in types (int, float, char etc.).
* Two operators = and & are already overloaded by default in C++. 
   For example: To copy objects of 	same class, you can directly use = operator. 
   You do not need to create an operator function.
* Operator overloading cannot change the precedence and associatively of operators. 
  However, if you want to change the order of evaluation, parenthesis should be used.
* There are 4 operators that cannot be overloaded in C++. 
  They are :: (scope resolution), . (member selection), .* (member selection through pointer to function) and ?: (ternary operator).


## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 18: Operator Overloading

[Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-c/)

*Egon Teiniker, 2020, GPL v3.0*

