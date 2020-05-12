#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <FileService.h>
#include <memory>

class Factory 
{
    public:
	virtual ~Factory(void) {}
        
	virtual std::shared_ptr<FileService> createFileService() = 0;
 };

#endif /*_FACTORY_H_ */
