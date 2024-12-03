#include <gtest/gtest.h>
#include <vector>

#include "resistor.h"
#include "capacitor.h"

using namespace std;

TEST(PartsTestGroup, ResistorTest) 
{
    // Setup 
    Resistor resistor(1, 1000, "Ohm");

    // Exercise + Verify
    EXPECT_EQ(1, resistor.id());
    EXPECT_NEAR(1000, resistor.value(), 1E-3);
    EXPECT_EQ("Ohm", resistor.unit());
    EXPECT_EQ("Resistor,1,1.000E+03,Ohm", resistor.to_csv());

    // Teardown
}

TEST(PartsTestGroup, CapacitorTest) 
{
    // Setup 
    Capacitor capacitor(2, 4.7E-6, "Farad");

    // Exercise + Verify
    EXPECT_EQ(2, capacitor.id());
    EXPECT_NEAR(4.7E-6, capacitor.value(), 1E-6);
    EXPECT_EQ("Farad", capacitor.unit());
    EXPECT_EQ("Capacitor,2,4.700E-06,Farad", capacitor.to_csv());

    // Teardown
}


TEST(PartsTestGroup, PolymorphTest) 
{
    // Setup 
    Part* resistor = new Resistor(1, 1000, "Ohm");
    Part* capacitor = new Capacitor(2, 4.7E-6, "Farad");
    
    // Exercise + Verify
    EXPECT_EQ("Resistor,1,1.000E+03,Ohm", resistor->to_csv());
    EXPECT_EQ("Capacitor,2,4.700E-06,Farad", capacitor->to_csv());

    Resistor* r = dynamic_cast<Resistor*>(resistor);
    EXPECT_NE(nullptr, r);

    // Teardown
    delete resistor;
    delete capacitor;
}


TEST(PartsTestGroup, PolymorphVectorTest) 
{
    // Setup 
    Part* resistor = new Resistor(1, 1000, "Ohm");
    Part* capacitor = new Capacitor(2, 4.7E-6, "Farad");
    vector<Part*> parts;    
    parts.push_back(resistor);
    parts.push_back(capacitor); 
    
    // Exercise + Verify
    EXPECT_EQ("Resistor,1,1.000E+03,Ohm", parts[0]->to_csv());
    EXPECT_EQ("Capacitor,2,4.700E-06,Farad", parts[1]->to_csv());
    
    // Teardown 
    delete parts[0];
    delete parts[1];
}
