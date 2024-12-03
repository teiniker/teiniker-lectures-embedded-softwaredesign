#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <string>

#include "part.h"

class Resistor : public Part
{
	public:                
		Resistor(const int id, const double value, const std::string& username)
			: Part(id, value, username) 
		{
		}


		std::string to_csv(void) const override;
};

#endif /*_RESISTOR_H_ */
