#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Product 
{
	private:
		int id_;
		std::string description_; 
		long price_;
 
	public:
		Product(int id, const std::string& description, long price); 
		Product(const Product& old);	// Copy Constructor
		
		int id(void);		
		std::string description(void);
		long price(void);
 };

#endif /*_PRODUCT_H_ */
