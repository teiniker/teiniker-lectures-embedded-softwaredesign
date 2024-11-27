#include "order_line.h"

OrderLine::OrderLine(int id, int quantity, Product* product)
	: Entity(id), _quantity{quantity}, _product{product}
{
}

int OrderLine::quantity(void)
{
	return _quantity;
}

Product* OrderLine::product(void)
{
	return _product;
}
