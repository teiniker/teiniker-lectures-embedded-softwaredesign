#ifndef _LIST_BUILDER_XML_H_
#define _LIST_BUILDER_XML_H_

#include <string>
#include <vector>
#include <list_builder.h>

class ListBuilderXml : public ListBuilder 
{
private:
    std::vector<std::string> list; 

public:    
    ListBuilder& item(const std::string& s);
    std::string toXml() const;
};



#endif /* _LIST_BUILDER_XML_H_ */