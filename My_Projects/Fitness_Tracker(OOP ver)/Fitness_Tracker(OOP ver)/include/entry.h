//
//  entry.h
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#pragma once
#include <string>
using namespace std;

class Entry{
protected:
    string name;
    double calories;
public:
    Entry();
    Entry(const string& name, const double& calories);
    // set the values
    void setName(const string& name);
    void setCalories(const double& calories);
    // get the values
    virtual string getName() const;
    virtual double getCalories() const;
    virtual ~Entry() {}
};
