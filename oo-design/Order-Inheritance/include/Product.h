#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

#include <Entity.h>

using namespace std;

class Product: public Entity
{
	private:
		string description_; 
		long price_;
 
	public:
		Product(int id, const string& description, long price); 

		string description(void);
		long price(void);
 };

#endif /*_PRODUCT_H_ */
