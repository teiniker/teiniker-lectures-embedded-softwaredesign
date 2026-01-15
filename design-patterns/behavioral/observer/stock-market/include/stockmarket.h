#pragma once

#include <iostream>
#include <subject.h>	

class StockMarket : public Subject
{
	
private: 
	unsigned long _dax;
	unsigned long _dowJones;
	//...

public:
	StockMarket() = default;

	// Getter and Setter for DAX
	unsigned long dax() const { return _dax; }
	void dax(const unsigned long value)
	{
		std::cout << "StockMarket: Setting DAX to " << value << std::endl;
		_dax = value;
		notifyObservers();
	}	

	// Getter and Setter for Dow Jones
	unsigned long dowJones() const { return _dowJones; }
	void dowJones(const unsigned long value)
	{
		std::cout << "StockMarket: Setting Dow Jones to " << value << std::endl;
		_dowJones = value;
		notifyObservers();
	}

	//...
};
