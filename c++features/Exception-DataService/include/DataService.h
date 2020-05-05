#ifndef _DATASERVICE_H_
#define _DATASERVICE_H_

#include <FileService.h>

#include <string>
#include <vector>


class DataProcessingException : public std::exception 
{
	private:
		std::string cause_;
		
	public:
		DataProcessingException(const std::string& cause) : cause_{cause} {}
		
		const char* what() const noexcept
		{
			return cause_.c_str();
		}
};

class DataService 
{
	private:
		FileService* fservice_;
		std::vector<std::string> split(const std::string &s, char delim);
 
	public:                
		DataService(FileService* fservice);

		std::vector<int> readData();
		void writeData(const std::vector<int>& data);
 };

#endif /*_FILESERVICE_H_ */
