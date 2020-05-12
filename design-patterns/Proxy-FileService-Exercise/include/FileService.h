#ifndef _FILESERVICE_H_
#define _FILESERVICE_H_

#include <string>

class FileNotFound : public std::exception 
{
	private:
		std::string cause_;
		
	public:
		FileNotFound(const std::string& cause) : cause_{cause} {}
		
		const char* what() const noexcept
		{
			return cause_.c_str();
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
