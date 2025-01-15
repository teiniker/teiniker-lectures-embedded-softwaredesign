#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <string>
#include <vector>
#include <memory>

class Display
{
private: 
    // Display buffer
    std::vector<std::string> _buffer;

    // Private static member for singleton
    static std::shared_ptr<Display> instance;

    // Private constructor to prevent direct instantiation
    Display() {};

public:
    // Singleton
    static std::shared_ptr<Display> getInstance();

    // Operations
    void print(const std::string& msg);
    void print(const int i);
    void print(const double d);
    
    std::vector<std::string>& getBuffer(void);

private:
    // Singletons should not be cloneable.
    Display(Display &other) = delete;

    // Singletons should not be assignable.
    void operator=(const Display &) = delete;
};

#endif // _DISPLAY_H_