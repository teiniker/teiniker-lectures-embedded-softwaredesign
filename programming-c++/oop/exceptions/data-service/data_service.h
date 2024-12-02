#ifndef _DATA_SERVICE_H_
#define _DATA_SERVICE_H_

#include <string>
#include <vector>

#include "file_service.h"

class DataProcessingException : public std::exception 
{
	private:
		std::string _cause;
		
	public:
		DataProcessingException(const std::string& cause) 
		: _cause{cause} 
		{
		}
		
		const char* what() const noexcept
		{
			return _cause.c_str();
		}
};

class DataService 
{
	private:
		FileService* _fservice;
		std::vector<std::string> split(const std::string &s, char delim);
 
	public:                
		DataService(FileService* fservice);

		std::vector<int> readData();
		void writeData(const std::vector<int>& data);
 };

#endif /*_FILESERVICE_H_ */
