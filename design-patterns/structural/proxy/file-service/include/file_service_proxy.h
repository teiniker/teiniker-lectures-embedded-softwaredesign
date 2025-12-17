#ifndef _FILE_SERVICE_PROXY_H_
#define _FILE_SERVICE_PROXY_H_

#include <memory>
#include <string>
#include <file_service.h>

class FileServiceProxy : public FileService 
{
	private:
		std::shared_ptr<FileService> service_;
 
	public:                
		FileServiceProxy(std::shared_ptr<FileService> service);

		std::string readFile(std::string& filename);
		//...
		
 };

#endif /*_FILE_SERVICE_PROXY_H_ */
