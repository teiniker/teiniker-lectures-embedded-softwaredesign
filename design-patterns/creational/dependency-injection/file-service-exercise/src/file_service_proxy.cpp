#include <string>
#include <memory>
#include <stdexcept>

#include <file_service_proxy.h>
#include <file_service_impl.h>

using namespace std;

FileServiceProxy::FileServiceProxy(void)
{
	_service = new FileServiceImpl();
}

FileServiceProxy::~FileServiceProxy(void)
{
	delete _service;
}

string FileServiceProxy::readFile(const string& filename)
{
	// Input Validation (Pre-Processing)
	if(!endsWith(filename, ".data"))
		throw invalid_argument("Invalid filename!");
		
	// Delegation
	string content = _service->readFile(filename);

	// Post-Processing
	return content;	
}


bool FileServiceProxy::endsWith(const string& s, const string& suffix)
{
    return s.rfind(suffix) == (s.size()-suffix.size());
}
