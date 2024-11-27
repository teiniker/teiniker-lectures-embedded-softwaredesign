#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include "entity.h"
#include "order_line.h"

class Order : public Entity  
{
	private:
		std::string _name;
		std::vector<OrderLine*> _lines;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const std::string& name);	
		   
		std::string name(void);

		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };

#endif /*_ORDER_H_ */
