#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity 
{
	private:
		int id_; 
 
	public:
		Entity(int id)
			: id_{id}
		{
		}	
		   
		int id(void)
		{
			return id_;
		}		
 };

#endif /*_ENTITY_H_ */
