#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include "entity.h"
#include "product.h"

class OrderLine : public Entity 
{
	private:
		int _quantity;
		Product* _product; // ---[0..1]-> Product
 
	public:
		OrderLine(int id, int quantity, Product* product);

		int quantity(void);
		Product* product(void);
 };

#endif /*_ORDERLINE_H_ */
