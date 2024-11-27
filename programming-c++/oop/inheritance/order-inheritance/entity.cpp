#include "entity.h"

Entity::Entity(int id)
	: _id{id}
{
}	
		   
int Entity::id(void)
{
	return _id;
}		
