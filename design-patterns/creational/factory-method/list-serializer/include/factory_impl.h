#ifndef _FACTORY_IMPL_H_
#define _FACTORY_IMPL_H_

#include <memory>
#include <factory.h>
#include <list_serializer.h>

class FactoryImpl : public Factory 
{
    public:
	std::shared_ptr<ListSerializer> createSerializer(SerializerType type);
 };

#endif /*_FACTORY_IMPL_H_ */
