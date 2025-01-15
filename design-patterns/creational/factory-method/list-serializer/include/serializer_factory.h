#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <memory>

#include <list_serializer.h>

enum class SerializerType
{
	XML,
	JSON
};

class Factory 
{
    public:
	virtual ~Factory(void) {}
        
	virtual std::shared_ptr<ListSerializer> createSerializer(SerializerType type) = 0;
 };

#endif /*_FACTORY_H_ */
