#include <FileServiceProxy.h>

#include <string>

using namespace std;

FileServiceProxy::FileServiceProxy(shared_ptr<FileService> service)
	: service_{service}
{
}

string FileServiceProxy::readFile(const string& filename)
{
	// Pre-Processing
	if(!endsWith(filename, ".data"))
		throw invalid_argument("Invalid filename!");
		
	// Delegation
	string content = service_->readFile(filename);
	
	// Post-Processing
	return content;	
}


bool FileServiceProxy::endsWith(const string& s, const string& suffix)
{
    return s.rfind(suffix) == (s.size()-suffix.size());
}
