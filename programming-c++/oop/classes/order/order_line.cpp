#include "order_line.h"

using namespace std;

OrderLine::OrderLine(int id, int quantity, Product* product)
	: _id{id}, _quantity{quantity}, _product{product}
{
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
