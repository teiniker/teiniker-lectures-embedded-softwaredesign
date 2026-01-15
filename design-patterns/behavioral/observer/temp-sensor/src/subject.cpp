#include <subject.h>

using namespace std;

void Subject::attach(std::shared_ptr<Observer> observer)
{
	observers.push_back(observer);
}
	
void Subject::detach(std::shared_ptr<Observer> observer)
{
	for (auto it = observers.begin(); it != observers.end(); ++it)
	{
		if (it->get() == observer.get())
		{
			observers.erase(it);
			break;
		}
	}
}

void Subject::notifyObservers()
{
	for (const auto& observer : observers)
	{
		observer->update(shared_from_this());
	}
}
