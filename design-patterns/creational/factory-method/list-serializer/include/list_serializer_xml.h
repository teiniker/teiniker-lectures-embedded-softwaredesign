#ifndef _LIST_SERIALIZER_XML_H_
#define _LIST_SERIALIZER_XML_H_

#include <string>
#include <vector>
#include "list_serializer.h"

class ListSerializerXml : public ListSerializer 
{
public:    
    std::string serialize(const std::vector<int>& list);
    //...
};

#endif /* _LIST_SERIALIZER_XML_H_ */