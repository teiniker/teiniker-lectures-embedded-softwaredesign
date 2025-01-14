#ifndef _LIST_SERIALIZER_JSON_H_
#define _LIST_SERIALIZER_JSON_H_

#include <string>
#include <vector>
#include "list_serializer.h"

class ListSerializerJson : public ListSerializer 
{
public:    
    std::string serialize(const std::vector<int>& list);
    //...
};

#endif /*_LIST_SERIALIZER_JSON_H_ */