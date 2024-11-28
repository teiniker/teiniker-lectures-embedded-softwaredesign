# Example: EEPROM Using operator[]

The `operator[]` in the EEPROM class is designed to provide **array-like 
access** to the EEPROM's memory, allowing users to read from and write 
to specific memory addresses using the subscript `[]` syntax.

Operator signature:

```C++ 
    uint8_t& operator[](const uint32_t address);
```

* Returns a reference to a `uint8_t` value.
    By returning a reference, it allows both **reading and modifying** the 
    byte stored at the specified address.

* The `address` (index) within the EEPROM memory where the operation 
    is to be performed.    

With this operator the following use cases are possible:

* **Reading a byte from EEPROM**:
    ```C++
    uint8_t value = eeprom[10]; 
    ```

* **Writing a byte to EEPROM**:

    ```C++ 
    eeprom[10] = 0xFF;
    ```

* **Modifying a byte in EEPROM**:

    ```C++ 
    eeprom[20] += 5;
    ```    

The overloaded `operator[]` in the EEPROM class enhances usability 
by allowing users to access and manipulate EEPROM memory using 
familiar array syntax. 

*Egon Teiniker, 2020-2024, GPL v3.0*