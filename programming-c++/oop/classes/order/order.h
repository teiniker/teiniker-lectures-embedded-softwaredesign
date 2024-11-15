#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include "order_line.h"

class Order 
{
 	private:
		int _id; 
		std::string _name;
		std::vector<OrderLine*> _lines;  // ---[*]-> OrderLine

 	public:
		Order(int id, const std::string& name);	
		   
		int id(void);		
		std::string name(void);
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 
 };

#endif /*_MAIL_H_ */
