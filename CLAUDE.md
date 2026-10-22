# Repository Instructions

## Repository Overview
This is an educational repository containing **examples, exercises, and model 
solutions** for teaching programming in C++.
These small examples are distributed in different folders.

### High-Level Organization

The repository follows the structure of a lecture on software design and
architectures for embedded systems. The root `README.md` is the table of
contents and links to the `README.md` of each topic.

```
introduction/            Course introduction (documentation only)
    software-design/         What software design is about
    agentic-engineering/     Working with AI coding agents
solid-principles/        SOLID class design principles (documentation only)
design-patterns/         GoF design patterns with C++ examples
    introduction/            Introduction to design patterns
    creational/              builder, dependency-injection, factory-method,
                             replace-constructor, singleton
    structural/              adapter, composite, decorator, facade, proxy
    behavioral/              observer, state, strategy, template-method
architectures/           Software architectures (mostly documentation)
    introduction/            Introduction to software architectures
    layered/                 Layered architectures
    client-server/           Client-server (translator demo, Java .jar)
    message-oriented/        Message-oriented (Mosquitto MQTT broker)
    microservices/           Microservices (book-service, Python)
```

#### Design Pattern Examples

All C++ code lives in `design-patterns/<category>/<pattern>/<example>/`.
Each pattern directory has a `README.md` explaining the pattern, and each
example is a self-contained CMake project with the following layout:

```
<example>/
    CMakeLists.txt       Top-level project (C++17, finds GTest, adds src/test)
    include/             Header files (*.h)
    src/                 Implementation (*.cpp), built as a static library
        CMakeLists.txt
    test/                Google Test cases
        CMakeLists.txt   Builds the `test` executable
        test.cpp
    figures/             UML diagrams used in the README (optional)
    README.md            Description of the example (optional)
```

- Exercises (`*-exercise`) sit next to their model solution in the same
    pattern directory, e.g. `proxy/file-service` and
    `proxy/file-service-exercise`.
- Some examples only demonstrate a variant of a pattern
    (e.g. `singleton/logger-variant`) and have no exercise.
- Directories without a `CMakeLists.txt` (`introduction`, `solid-principles`,
    most of `architectures`) contain only Markdown and figures.


## Build and Test Commands

Use cmake to build projects.
Every subdirectory contains a `CMakeLists.txt`.
Use `./build` directory to store build artifacts.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/test
```

### Testing Framework
Projects use the Google testing framework.

## Key Conventions

### Naming Conventions

- **Exercise directories**: Suffix with `-exercise` (e.g., `resistor-exercise`)
- **Model solution directories**: No suffix (e.g., `resistor`)
- **Test files**: Named `test.cpp`
- **Source organization**: Each logical unit (functions, structures,
    algorithms) has its own subdirectory
- **Accessors**: Getter matches the property name (e.g. `title()`);
    setter is prefixed with `set_` (e.g. `set_title()`)

### Coding Standard

- **Line width**: Maximum **80 characters** per line
- **Indentation**: **4 spaces** per level (not tabs)
- **Braces**: 
  - Always surround blocks with braces `{ }`, even for single statements
  - Left brace `{` goes on the next line after the statement
  - Right brace `}` aligns with the opening keyword
- **Spacing**:
  - Binary operators (`+`, `-`, `*`, `/`, `==`, etc.) surrounded by spaces
  - Unary operators (`++`, `--`, `!`, `~`) have no space on operand side
  - Pointer operators (`*`, `&`) have spaces in declarations but not
    on operand side
  - No spaces around member/arrow operators (`.`, `->`, `[`, `]`)
- **Variable declarations**: First characters aligned within a block
- **Blank lines**: Before and after natural blocks of code (loops,
    if/else, declarations)

#### Example

```c++
class Book 
{
private:
    std::string _title;
    std::string _author;
    std::string _isbn;

public:
    // Initializing Constructor
    Book(const std::string& title, const std::string& author,
        const std::string& isbn);

    // Copy Constructor
    Book(const Book &book) = default;

    // Default destructor
    ~Book() = default;  

    // Getter and Setter Methods
    std::string title() const { return _title; }
    void set_title(const std::string& title) { _title = title; }

    std::string author() const { return _author; }
    void set_author(const std::string& author) { _author = author; }

    std::string isbn() const { return _isbn; }
    void set_isbn(const std::string& isbn) { _isbn = isbn; }
};
```


### Documentation

- Use only 80 chars per line for documentation text.
- Don't use —, ---, and emojis in generated text.
- Use Mermaid to generate class diagrams.
    - Use direction LR
    - Add a : between an attribute name and type, e.g. id:int
    - Make the constructor static (add $ at the end)