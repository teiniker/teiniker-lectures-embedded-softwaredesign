#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <string>

#include <Entity.h>
#include <Product.h>

using namespace std;

class OrderLine: public Entity 
{
	private:
		int quantity_;
		Product* product_; // ---[0..1]-> Product
 
	public:
		OrderLine(int id, int quantity, Product* product);

		int quantity(void);
		Product* product(void);
 };

#endif /*_ORDERLINE_H_ */
