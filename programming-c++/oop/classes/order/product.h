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

		int id(void);		
		std::string description(void);
		long price(void);
};

#endif /*_PRODUCT_H_ */
