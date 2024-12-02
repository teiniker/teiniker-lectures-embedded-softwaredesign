# Example: Input Validation

Input validation in C++ is the process of **verifying that the data 
provided by the user meets certain criteria** before it is processed 
or used in the program. 

This ensures the **integrity**, **reliability**, and **security** of 
the program by preventing invalid, unexpected, or malicious inputs 
from causing errors or vulnerabilities.

_Example:_ Validate parameters passed to a constructor.

```C++
User::User(const int id, const string& username, const string& password)
{
    // Input Validation (Pre-Condition Checks)
    if(id < 0)
        throw invalid_argument("Invalid id!");
        
    if(username.length() < 4 || username.length() > 40)
        throw invalid_argument("Invalid username!");
        
    if(password.length() < 10)
        throw invalid_argument("Invalid password!");
        
    // Object initialization	
    _id = id;	
    _username = username;
    _password = password;
}
```

The purpose of the constructor is to initialize an object of the 
`User` class while performing input validation to ensure the 
provided arguments meet specified requirements.

* If **id is negative**, the constructor throws an `invalid_argument` 
exception with the message `"Invalid id!"`.    

* If **username is shorter than 4 characters or longer than 40 characters**, 
the constructor throws an `invalid_argument` exception with the 
message `"Invalid username!"`.

* If **password is shorter than 10 characters**, the constructor throws 
an `invalid_argument` exception with the message `"Invalid password!"`.


_Example:_ Testing excepion handling

```C++
TEST_F(UserTest, InvalidUsernameTooLongTest) 
{
    string username = "1234567890123456789012345678901234567890X";
    EXPECT_THROW(User(1, username, "c3R1ZGVudA"), std::invalid_argument);
}
```

* **EXPECT_THROW**:
    * This macro checks that the provided expression (in this case, 
    `User(1, username, "c3R1ZGVudA")`) throws an exception of a specific 
    type.
    * If the exception is thrown and matches the expected type 
    (`std::invalid_argument`), the test passes.
    * If no exception or a different type of exception is thrown, 
    the test fails.

_Egon Teiniker, 2020-2024, GPL v3.0_    