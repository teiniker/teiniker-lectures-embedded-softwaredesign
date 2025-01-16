#pragma once

#include <list_processor.h>

class ListToLower : public ListProcessor
{
protected:
    // Primitive Operation (required override)
    std::string modifyElement(const std::string& element) override;

    // Hook Operation (optional override)
    void printElement(const std::string& element) override;
};


