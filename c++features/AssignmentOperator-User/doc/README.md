# Assignment Operator

The assignment operator (operator=) is used to copy values from one object 
to another already existing object.

```C++
    ClassName& operator =(const lassName& orig);
```

The purpose of the copy constructor and the assignment operator are almost 
equivalent -- both copy one object to another. 

**The copy constructor initializes new objects, whereas the assignment operator 
replaces the contents of existing objects.**

The assignment operator must be overloaded as a member function.
	
The overloaded operator= returns *this, so that we can chain multiple 
assignments together.
	

## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 3.3: Copy and Move

[Overloading the assignment operator](https://www.learncpp.com/cpp-tutorial/9-14-overloading-the-assignment-operator/)

*Egon Teiniker, 2020, GPL v3.0*
