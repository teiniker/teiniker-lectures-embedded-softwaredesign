
#include <memory>
#include <factory_impl.h>
#include <file_service_impl.h>

using namespace std;

shared_ptr<FileService> FactoryImpl::createFileService(void)
{
	// Instantiantion logic
	shared_ptr<FileService> service(new FileServiceImpl());
	return service;
}
