#ifndef _FILE_SERVICE_DECORATOR_H_
#define _FILE_SERVICE_DECORATOR_H_

#include <memory>
#include <string>
#include <file_service.h>

// Abstract and concrete Decorator
class FileServiceDecorator : public FileService 
{
	private:
		std::shared_ptr<FileService> service_;
 
	public:                
		FileServiceDecorator(std::shared_ptr<FileService> service);

		std::string readFile(std::string& filename);
		//...
		
 };

#endif /*_FILE_SERVICE_DECORATOR_H_ */
