#include <observer.h>
#include <stockmarket.h>

// DaxObserver implementation

DaxObserver::DaxObserver(std::shared_ptr<StockMarket> stockMarket) : _stockMarket(stockMarket), _lastDax(0)
{
}

void DaxObserver::update()
{
    _lastDax = _stockMarket->dax();
}

// DowObserver implementation

DowObserver::DowObserver(std::shared_ptr<StockMarket> stockMarket) : _stockMarket(stockMarket), _lastDowJones(0)
{
}

void DowObserver::update()
{
    _lastDowJones = _stockMarket->dowJones();
}
