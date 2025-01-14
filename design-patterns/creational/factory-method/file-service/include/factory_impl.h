#ifndef _FACTORY_IMPL_H_
#define _FACTORY_IMPL_H_

#include <factory.h>
#include <file_service.h>

class FactoryImpl : public Factory 
{
    public:
	virtual std::shared_ptr<FileService> createFileService(void);
 };

#endif /*_FACTORY_IMPL_H_ */
