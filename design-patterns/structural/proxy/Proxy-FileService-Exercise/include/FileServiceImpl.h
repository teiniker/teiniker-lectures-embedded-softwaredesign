#ifndef _FILESERVICEIMPL_H_
#define _FILESERVICEIMPL_H_

#include <FileService.h>

class FileServiceImpl : public FileService 
{
	public:                
		
		std::string readFile(const std::string& filename);
		//...
 };

#endif /*_FILESERVICEIMPL_H_ */
