# Header File vs. Implementation File 

In C++, splitting a class implementation into a header file (`.h`) and 
a source file (`.cpp`) is a common practice for maintaining code organization, 
improving readability, and supporting modular development. 


## When to Split Implementation into Header and Source Files

* **Code Organization and Modularity:**
   * For large projects, separating class definitions (in headers) from 
   implementations (in source files) improves clarity and makes it easier to 
   navigate code.
   * It allows multiple developers to work on different parts of the project simultaneously without conflicts.

* **Reusability and Encapsulation:**
   * Headers serve as interfaces, making it clear what functionality a 
   class provides without exposing implementation details.
   * This is particularly useful for library development, where only the 
   headers are exposed to users, while the implementation remains private.

* **Compilation Time Optimization:**
   * Changes to a `.cpp` file only require recompiling that file and relinking, 
   whereas changes in a header file can trigger recompilation of all files that 
   include it.


## Methods That Can Be Implemented in the Header File

* **Inline Methods:**
   * Functions defined directly in the header are treated as **inline** 
   by the compiler. Inline functions are substituted at the call site 
   during compilation, which can improve performance by avoiding function 
   call overhead.
   
   _Example:_
    ```cpp
    class MyClass
    {
    public:
         void setValue(int v) { value = v; } // Inline implementation
    private:
         int value;
    };
    ```
   * Inline implementation is suitable for small, frequently called methods 
   where performance is critical.

* **Simple Accessors or Mutators:**
    * Simple getter and setter methods are often defined in the header 
    for convenience.
    
    _Example:_
    ```cpp
    class MyClass 
    {
    public:
        int getValue() const { return value; }
    private:
        int value;
    };
    ```

* **Templates:**
    * Templates must be fully implemented in the header file because the 
    compiler needs the full definition to generate the required instances 
    during compilation.
    
    _Example:_
    ```cpp
    template <typename T>
    class MyTemplate 
    {
    public:
        void setValue(T v) { value = v; }
    private:
        T value;
    };
    ```

## Common Practices

* **Header Implementation (Inline):**
   - For short and performance-critical methods (e.g., getters, setters).
   - For methods that are unlikely to change frequently.
   - For template classes or functions.

* **Source File Implementation:**
   - For complex or large methods that are rarely called.
   - When we want to hide implementation details and reduce dependencies.
   - To improve maintainability and reduce compile times in larger projects.


## Conclusion
Splitting the implementation between header and source files is a trade-off 
between simplicity, performance, and modularity. Use the header for small, 
frequently used, or inlineable methods, and the `.cpp` file for larger or 
more complex logic to maintain a clean and maintainable codebase.


*Egon Teiniker, 2020-2025, GPL v3.0*
