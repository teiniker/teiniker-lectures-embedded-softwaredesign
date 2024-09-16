#ifndef _FACTORYIMPL_H_
#define _FACTORYIMPL_H_

#include <Factory.h>

class FactoryImpl : public Factory 
{
    public:
	virtual std::shared_ptr<FileService> createFileService();
 };

#endif /*_FACTORYIMPL_H_ */
