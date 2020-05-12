#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <Mail.h>
#include <string>
#include <memory>

class Factory 
{
	public:
		virtual ~Factory(void) {}
    
		virtual std::shared_ptr<Mail> createMail(const std::string& address) = 0;
 };

#endif /*_FACTORY_H_ */
