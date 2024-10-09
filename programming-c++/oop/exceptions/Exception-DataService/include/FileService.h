#ifndef _FILESERVICE_H_
#define _FILESERVICE_H_

#include <string>
#include <fstream> 


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
	private:
		std::string filename_;
 
	public:                
		FileService(const std::string& filename);

		std::string readFile();
		void writeFile(const std::string& content);
 };

#endif /*_FILESERVICE_H_ */
