#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

using namespace std;

class Product 
{
	private:
		int id_;
		string description_; 
		long price_;
 
	public:
		Product(int id, const string& description, long price); 

		int id(void);		
		string description(void);
		long price(void);
 };

#endif /*_PRODUCT_H_ */
