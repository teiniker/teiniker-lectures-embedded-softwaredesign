#include "product.h"

using namespace std;

Product::Product(int id, const string& description, long price) 
	: Entity(id), _description{description}, _price{price}
{
}

string Product::description(void)
{
	return _description;
}

long Product::price(void)
{
	return _price;
} 
