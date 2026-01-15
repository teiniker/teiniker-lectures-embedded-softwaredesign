#pragma once

#include <iostream>
#include <subject.h>	

class TempSensor : public Subject
{
	
private: 
	double _temperature;
	double _humidity;

public:
	TempSensor() = default;

	// Getter and Setter for Temperature
	double temperature() const 
	{ 
		return _temperature; 
	}	
	void temperature(double temperature) 
	{ 
		std::cout << "TempSensor: Setting temperature to " << temperature << std::endl;
		_temperature = temperature; 
		notifyObservers(); 
	}

	// Getter and Setter for Humidity
	double humidity() const 
	{ 
		return _humidity; 
	}
	void humidity(double humidity) 
	{ 
		std::cout << "TempSensor: Setting humidity to " << humidity << std::endl;
		_humidity = humidity; 
		notifyObservers(); 
	}
};
