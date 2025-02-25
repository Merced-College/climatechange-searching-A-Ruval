// StateClimate.h
#ifndef STATECLIMATE_H
#define STATECLIMATE_H

#include <iostream>

class StateClimate {
private:
    int fips;
    int year;
    double temp;
    double tempc;
    std::string stateName;

public:
    // Constructor
    StateClimate(int f, int y, double t, double tc, std::string name);

    // Getters
    int getFips() const;
    int getYear() const;
    double getTemp() const;
    double getTempC() const;
    std::string getStateName() const;

    // Setters
    void setFips(int f);
    void setYear(int y);
    void setTemp(double t);
    void setTempC(double tc);
    void setStateName(std::string name);

    // Display function
    void display() const;
};

#endif // STATECLIMATE_H
