#ifndef _FILE_SERVICE_H_
#define _FILE_SERVICE_H_

#include <string>
#include <fstream> 

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
	private:
		std::string _filename;
 
	public:                
		FileService(const std::string& filename);

		std::string readFile();
		void writeFile(const std::string& content);
 };

#endif /*_FILE_SERVICE_H_ */
