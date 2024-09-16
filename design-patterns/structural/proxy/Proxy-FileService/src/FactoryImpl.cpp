
#include <FactoryImpl.h>
#include <FileServiceImpl.h>
#include <FileServiceProxy.h>
#include <memory>

using namespace std;

shared_ptr<FileService> FactoryImpl::createFileService()
{
	// --->[:FileServiceProxy]--->[:FileServiceImpl]
	shared_ptr<FileService> impl(new FileServiceImpl());
    shared_ptr<FileService> service(new FileServiceProxy(impl));
	return service;
}
