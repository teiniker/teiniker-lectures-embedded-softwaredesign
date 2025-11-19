#ifndef _FILESERVICE_H_
#define _FILESERVICE_H_

#include <string>

class FileNotFound : public std::exception 
{
	private:
		std::string _cause;
		
	public:
		FileNotFound(const std::string& cause) : _cause{cause} {}
		
		const char* what() const noexcept
		{
			return _cause.c_str();
		}
};

class FileService 
{
	public:                
		virtual ~FileService(void) {}
		
		virtual std::string readFile(const std::string& filename) = 0;
		//...
 };

#endif /*_FILESERVICE_H_ */
