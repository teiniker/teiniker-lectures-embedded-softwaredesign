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
		Product* product_;
 
	public:
		OrderLine(int id, int quantity, Product* product);

		int id(void);
		int quantity(void);
		Product* product(void);
 };

#endif /*_ORDERLINE_H_ */
