#pragma once

#include <memory>

class StockMarket; // Forward declaration

class Observer
{
public:
	virtual ~Observer() = default;

	virtual void update() = 0;
};


class DaxObserver : public Observer
{
private:
	std::shared_ptr<StockMarket> _stockMarket;
	unsigned long _lastDax;

public:
	DaxObserver(std::shared_ptr<StockMarket> stockMarket);

	unsigned long lastDax() const 
	{ 
		return _lastDax; 
	}

	void update() override;
};


class DowObserver : public Observer
{
private:
	std::shared_ptr<StockMarket> _stockMarket;
	unsigned long _lastDowJones;

public:
	DowObserver(std::shared_ptr<StockMarket> stockMarket);

	unsigned long lastDowJones() const 
	{ 
		return _lastDowJones; 
	}

	void update() override;
};