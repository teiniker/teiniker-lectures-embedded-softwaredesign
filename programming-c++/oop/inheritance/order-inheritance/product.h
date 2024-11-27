#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include "entity.h"


class Product : public Entity
{
	private:
		std::string _description; 
		long _price;
 
	public:
		Product(int id, const std::string& description, long price); 

		std::string description(void);
		long price(void);
};

#endif /*_PRODUCT_H_ */
