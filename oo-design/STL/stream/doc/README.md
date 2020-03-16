# Standard Library: I/O Streams

The I/O strea library provides formatted and unformatted buffered I/O
of text and numeric values.

## Standard Output Streams
The **ostream** library defines output for every build-in type.
The **<<** is used as an output operator. **cout** is the 
standard output stream and **cerr** ist der standard stream for 
reporting errors.
By default, values written to *cout* are converted to a sequence of 
characters.

```C++
    string hello = "Hello"; 
    cout << hello << " Graz!" << endl;
```
 
## String Streams

The standard library also provides streams to and from a string.
String streams provide a buffer but aon't have an I/O channel.

```C++
    ostringstream oss;
    oss << 1234 << ' ' << "abcdef";
```
The result from an **ostringstream** can be read using **str()**.

INput string streams are mainly used for formated reading from existing 
strings.

```C++
    string data = "1234 abcdef"; 
    istringstream iss(data);
    
    int number;
    string text;
    iss >> number;
    iss >> text;
```

## Formatting

The iostream library provides a large set of operators for controlling 
the format of input and output.
The simplest formatting controls are called **manipulators**.

```C++
    ostringstream oss;
    oss << hex << uppercase << 1234;
    oss << ' ';
    oss << fixed << setprecision(2) << 3.1415;
```

## References
Nicolai M. Josuttis. The C++ Standard Library: A Tutorial and Reference. Addison Wesley 2012

[<iostream>](http://www.cplusplus.com/reference/iostream/)
    
[<sstream>](http://www.cplusplus.com/reference/sstream/)

[<iomanip>](http://www.cplusplus.com/reference/iomanip/)

*Egon Teiniker, 2020, GPL v3.0*
