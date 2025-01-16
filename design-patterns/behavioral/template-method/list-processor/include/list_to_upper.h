#pragma once

#include <list_processor.h>

class ListToUpper : public ListProcessor
{
protected:
    // Primitive Operation (required override)
    std::string modifyElement(const std::string& element) override;
};
