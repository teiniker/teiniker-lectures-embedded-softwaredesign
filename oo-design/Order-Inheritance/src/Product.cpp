#include <Product.h>

Product::Product(int id, const string& description, long price) 
	: Entity(id), description_{description}, price_{price}
{
}

string Product::description(void)
{
	return description_;
}

long Product::price(void)
{
	return price_;
} 
