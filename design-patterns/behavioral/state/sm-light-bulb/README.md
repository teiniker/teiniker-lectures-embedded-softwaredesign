# Example: Light Bulb State Machine

## Another Singleton Implementation

In this implementation, **`getInstance()`** creates and returns a **static** 
shared pointer to a single **`LightBulbOff`** object:

```cpp
std::shared_ptr<LightBulbOff> LightBulbOff::getInstance()
{
    static std::shared_ptr<LightBulbOff> instance(new LightBulbOff());
    return instance;
}
```

1. **Static Local Variable**:  
   The `static std::shared_ptr<LightBulbOff> instance` inside the function 
   is allocated exactly **once** during the entire program execution, at 
   the moment this code is first called. 
   All subsequent calls to `getInstance()` return the **same** `shared_ptr` 
   instance.  

2. **Private Constructor**:  
   Because `LightBulbOff`’s constructor is `private`, no external code can 
   instantiate it using `new LightBulbOff()`. The only way to get a 
   `LightBulbOff` object is via `getInstance()`.  

3. **Singleton-like Behavior**:  
   - The static variable ensures only one `LightBulbOff` object exists.  
   - Calling `LightBulbOff::getInstance()` will always return a pointer 
   to that **single** object.  

Together, these constraints fulfill the **Singleton** pattern in C++:
- **One instance** is created (and only once).
- Global access through `getInstance()` (no direct constructor calls 
outside the class).



## Casting of shared_ptr<>

The **`std::dynamic_pointer_cast<LightBulbOff>(...)`** is a **downcast** from 
the base pointer type (`std::shared_ptr<LightBulbState>`) to the derived pointer 
type (`std::shared_ptr<LightBulbOff>`). 

1. **`sm.getState()`** returns a `std::shared_ptr<LightBulbState>`, the base type.

2. We know (or suspect) at runtime that the actual object might be a **`LightBulbOff`** 
   instance.  

3. **`std::dynamic_pointer_cast<LightBulbOff>(...)`** checks the **runtime type** of 
   the object behind that pointer:
   - If the object is indeed a `LightBulbOff`, then the call returns a valid `std::shared_ptr<LightBulbOff>`.  
   - If the object is *not* a `LightBulbOff`, the call returns **`nullptr`**.

We use `std::dynamic_pointer_cast` to safely confirm the object’s actual 
(dynamic) type, and only then proceed as if it’s a `LightBulbOff`.

In these test cases, we check the state of the State Machine to verify that
the correct state is returned by the `getState()` method. 

```cpp
TEST(StateTest, testTurnOnAndTurnOn)
{
    // Turn on once
    sm.turnOn();
    auto onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);

    // Turn on again
    sm.turnOn();
    onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);
}
```

*Egon Teiniker, 2020-2025, GPL v3.0*