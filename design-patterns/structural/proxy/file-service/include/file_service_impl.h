#ifndef _FILESERVICEIMPL_H_
#define _FILESERVICEIMPL_H_

#include <string>
#include <file_service.h>

class FileServiceImpl : public FileService 
{
	public:                
		
		std::string readFile(const std::string& filename) override;
		//...
 };

#endif /*_FILESERVICEIMPL_H_ */
