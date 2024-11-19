#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include "line.h"

class Order 
{
	private:
		int _id; 
		std::string _name;
		std::vector<OrderLine*> _lines;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const std::string& name);	
		// TODO: Copy Constructor   
		   
		int id(void) const;		
		std::string name(void) const;
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };

#endif /*_MAIL_H_ */
