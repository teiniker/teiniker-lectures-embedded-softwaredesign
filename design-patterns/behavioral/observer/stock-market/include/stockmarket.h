#pragma once

#include <subject.h>	

// StockMarket class representing the Subject in the Observer pattern
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
		_dax = value;
		notifyObservers();
	}	

	// Getter and Setter for Dow Jones
	unsigned long dowJones() const { return _dowJones; }
	void dowJones(const unsigned long value)
	{
		_dowJones = value;
		notifyObservers();
	}

	//...
};
