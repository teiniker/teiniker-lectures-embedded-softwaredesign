#include <iostream>
#include <temp_sensor.h>

using namespace std;

// Display implementation

void Display::update(std::shared_ptr<Subject> subject)
{
    // Downcast to TempSensor to access temperature and humidity
    auto tempSensor = std::dynamic_pointer_cast<TempSensor>(subject);
    _temperature = tempSensor->temperature();
    _humidity = tempSensor->humidity();
    cout << "Display: Notified. New Temperature: " << _temperature << ", Humidity: " << _humidity << endl;
}


// Logger implementation
void Logger::update(std::shared_ptr<Subject> subject)
{
    // Downcast to TempSensor to access temperature and humidity
    auto tempSensor = std::dynamic_pointer_cast<TempSensor>(subject);
    _temperature = tempSensor->temperature();
    _humidity = tempSensor->humidity();
    cout << "Logger: Notified. New Temperature: " << _temperature << ", Humidity: " << _humidity << endl;
}
