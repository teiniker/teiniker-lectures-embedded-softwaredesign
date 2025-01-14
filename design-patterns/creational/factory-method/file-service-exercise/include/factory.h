#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <memory>
#include <file_service.h>

class Factory 
{
    public:
	virtual ~Factory(void) {}
        
	virtual std::shared_ptr<FileService> createFileService() = 0;
 };

#endif /*_FACTORY_H_ */
