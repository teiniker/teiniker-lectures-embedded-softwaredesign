#include <string>
#include <memory>
#include <stdexcept>

#include <file_service_decorator.h>

using namespace std;

FileServiceDecorator::FileServiceDecorator(shared_ptr<FileService> service)
	: service_{service}
{
}

string FileServiceDecorator::readFile(string& filename)
{
	// Pre-Processing
	filename += ".data";
		
	// Delegation
	string content = service_->readFile(filename);
	
	// Post-Processing
	return content;	
}
