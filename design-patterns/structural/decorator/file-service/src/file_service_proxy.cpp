#include <string>
#include <memory>
#include <stdexcept>

#include <file_service_proxy.h>

using namespace std;

FileServiceProxy::FileServiceProxy(shared_ptr<FileService> service)
	: service_{service}
{
}

string FileServiceProxy::readFile(string& filename)
{
	// Pre-Processing
	filename += ".data";
		
	// Delegation
	string content = service_->readFile(filename);
	
	// Post-Processing
	return content;	
}
