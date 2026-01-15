#pragma once

#include <vector>
#include <memory>

#include <observer.h>

// Subject class for the Observer pattern

class Subject : public std::enable_shared_from_this<Subject>
{
private:
	std::vector<std::shared_ptr<Observer>> observers;

public:
	Subject() = default;
	virtual ~Subject() = default;

	virtual void attach(std::shared_ptr<Observer>);
	virtual void detach(std::shared_ptr<Observer>);
	virtual void notifyObservers();
};

