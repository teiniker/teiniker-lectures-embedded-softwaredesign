#ifndef _LIST_BUILDER_JSON_H_
#define _LIST_BUILDER_JSON_H_

#include <string>
#include <vector>
#include "list-builder.h"

class ListBuilderJson : public ListBuilder 
{
private:
    std::vector<std::string> list; 

public:    
    ListBuilder& item(const std::string& s) override;
    std::string toJson() const;
};

#endif /*_LIST_BUILDER_JSON_H_ */