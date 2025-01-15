#ifndef _LIST_BUILDER_H_
#define _LIST_BUILDER_H_

#include <string>
#include <vector>

class ListBuilder
{
public:
    virtual ~ListBuilder() = default; 
    virtual ListBuilder& item(const std::string& s) = 0; 
};

#endif /*_LIST_BUILDER_H_ */
