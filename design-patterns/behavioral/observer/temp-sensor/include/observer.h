#pragma once

#include <memory>

class Subject; // Forward declaration
class TempSensor; // Forward declaration

class Observer
{
public:
	virtual ~Observer() = default;

	virtual void update(std::shared_ptr<Subject>) = 0;
};


class Display : public Observer
{
private:
	double _temperature;
	double _humidity;

public:
	Display(void) = default;

	double temperature() const 
	{ 
		return _temperature; 
	}

	double humidity() const 
	{ 
		return _humidity; 
	}

	void update(std::shared_ptr<Subject> subject) override;
};


class Logger : public Observer
{
private:
	double _temperature;
	double _humidity;

public:
	Logger(void) = default;

	double temperature() const 
	{ 
		return _temperature; 
	}

	double humidity() const 
	{ 
		return _humidity; 
	}

	void update(std::shared_ptr<Subject> subject) override;
};