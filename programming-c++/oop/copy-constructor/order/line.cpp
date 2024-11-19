#include "line.h"

using namespace std;

OrderLine::OrderLine(int id, int quantity, Product* product)
	: _id{id}, _quantity{quantity}, _product{product}
{
}

// Copy Constructor
OrderLine::OrderLine(const OrderLine& old)
{
	_id= old._id;
	_quantity = old._quantity;
	_product = new Product(*old._product);	
}


int OrderLine::id(void) const
{
	return _id;
}

int OrderLine::quantity(void) const
{
	return _quantity;
}

Product* OrderLine::product(void) const
{
	return _product;
}
void OrderLine::product(Product* product)
{
	_product = product;
}
