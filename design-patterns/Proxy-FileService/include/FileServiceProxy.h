#ifndef _FILESERVICEPROXY_H_
#define _FILESERVICEPROXY_H_

#include <FileService.h>
#include <memory>

class FileServiceProxy : public FileService 
{
	private:
		std::shared_ptr<FileService> service_;
 
	public:                
		FileServiceProxy(std::shared_ptr<FileService> service);

		std::string readFile(const std::string& filename);
		//...
		
	private:
		bool endsWith(const std::string& s, const std::string& suffix);
 };

#endif /*_FILESERVICEPROXY_H_ */
