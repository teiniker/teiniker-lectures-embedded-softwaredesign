#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include <Entity.h>
#include <OrderLine.h>

class Order: public Entity  
{
	private:
		string name_;
		std::vector<OrderLine*> lines_;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const string& name);	
		   
		string name(void);
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };

#endif /*_ORDER_H_ */
