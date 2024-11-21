#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Product 
{
	private:
		int _id;
		std::string _description; 
		long _price;

	public:
		Product(int id, const std::string& description, long price); 

		int id(void) const;		
		std::string description(void) const;
		long price(void) const;
};

#endif /*_PRODUCT_H_ */
