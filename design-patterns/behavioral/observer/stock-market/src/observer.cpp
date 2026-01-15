#include <iostream>
#include <observer.h>
#include <stockmarket.h>

using namespace std;

// DaxObserver implementation

DaxObserver::DaxObserver(std::shared_ptr<StockMarket> stockMarket) : _stockMarket(stockMarket), _lastDax(0)
{
}

void DaxObserver::update()
{
    cout << "DaxObserver: Notified. New DAX value is " << _stockMarket->dax() << endl;
    _lastDax = _stockMarket->dax();
}

// DowObserver implementation

DowObserver::DowObserver(std::shared_ptr<StockMarket> stockMarket) : _stockMarket(stockMarket), _lastDowJones(0)
{
}

void DowObserver::update()
{
    cout << "DowObserver: Notified. New Dow Jones value is " << _stockMarket->dowJones() << endl;
    _lastDowJones = _stockMarket->dowJones();
}
