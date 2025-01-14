#ifndef _LIST_SERIALIZER_H_
#define _LIST_SERIALIZER_H_

#include <string>
#include <vector>

class ListSerializer
{
public:
    virtual ~ListSerializer() = default; 
    virtual std::string serialize(const std::vector<int>& list) = 0; 
};

#endif /*_LIST_SERIALIZER_H_ */
