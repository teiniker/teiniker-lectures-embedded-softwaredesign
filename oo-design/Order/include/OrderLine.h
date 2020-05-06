#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <string>

#include <Product.h>

using namespace std;

class OrderLine 
{
	private:
		int id_; 
		int quantity_;
		Product* product_; // ---[0..1]-> Product
 
	public:
		OrderLine(int id, int quantity, Product* product);

		int id(void);
		int quantity(void);
		Product* product(void);
		//void product(Product* product);
 };

#endif /*_ORDERLINE_H_ */
