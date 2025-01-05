#ifndef _FACTORYIMPL_H_
#define _FACTORYIMPL_H_

#include <factory.h>

class FactoryImpl : public Factory 
{
    public:
        ~FactoryImpl(void) {}

	virtual std::shared_ptr<Mail> createMail(const std::string& address) override;
 };

#endif /*_FACTORYIMPL_H_ */
