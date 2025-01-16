#pragma once

#include <memory>
#include <vector>
#include <string>

class ListProcessor
{
public:
    virtual ~ListProcessor() = default; // Always good practice for base classes

    // Template Method
    void process(std::vector<std::string>& list);

protected:
    // Primitive Operation (pure virtual => must be overridden by subclasses)
    virtual std::string modifyElement(const std::string& element) = 0;

    // Hook Operation (provides a default implementation; can be overridden)
    virtual void printElement(const std::string& element);
};