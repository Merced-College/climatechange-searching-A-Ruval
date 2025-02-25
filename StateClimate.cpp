// StateClimate.cpp
#include "StateClimate.h"

// Constructor
StateClimate::StateClimate(int f, int y, double t, double tc, std::string name) : fips(f), year(y), temp(t), tempc(tc), stateName(name) {}

// Getters
int StateClimate::getFips() const { return fips; }
int StateClimate::getYear() const { return year; }
double StateClimate::getTemp() const { return temp; }
double StateClimate::getTempC() const { return tempc; }
std::string StateClimate::getStateName() const { return stateName; }

//Setters
void StateClimate::setFips(int f) { fips = f; }
void StateClimate::setYear(int y) { year = y;}
void StateClimate::setTemp(double t) { temp = t; }
void StateClimate::setTempC(double tc) { tempc = tc; }
void StateClimate::setStateName(std::string name) { stateName = name; }

// Display function
void StateClimate::display() const {
    std::cout << "FIPS: " << fips << ", Year: " << year 
              << ", Temp (F): " << temp << ", Temp (C): " << tempc << ", State: " << stateName << std::endl;
}
