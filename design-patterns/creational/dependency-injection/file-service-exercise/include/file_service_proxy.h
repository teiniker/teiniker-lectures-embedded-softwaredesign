#ifndef _FILE_SERVICE_PROXY_H_
#define _FILE_SERVICE_PROXY_H_

#include <memory>
#include <string>
#include <file_service.h>

class FileServiceProxy : public FileService 
{
	private:
		FileService *_service;
 
	public:                
		FileServiceProxy(void);
		virtual ~FileServiceProxy(void);

		std::string readFile(const std::string& filename);
		//...
		
	private:
		bool endsWith(const std::string& s, const std::string& suffix);
 };

#endif /*_FILE_SERVICE_PROXY_H_ */
