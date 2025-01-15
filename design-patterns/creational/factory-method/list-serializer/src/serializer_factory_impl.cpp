#include <memory>

#include <serializer_factory_impl.h>
#include <list_serializer_json.h>
#include <list_serializer_xml.h>

using namespace std;

shared_ptr<ListSerializer> FactoryImpl::createSerializer(SerializerType type)
{
	switch(type)
	{
		case SerializerType::XML:
			return make_shared<ListSerializerXml>();
		case SerializerType::JSON:
			return make_shared<ListSerializerJson>();
		default:
			return nullptr;
	}	
}
