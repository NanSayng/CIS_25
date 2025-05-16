//
//  meal.h
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#pragma once
#include "entry.h"

// inherit from entry class
class Meal:public Entry{
public:
    Meal();
    Meal(const string& name, const double& calories);
    
    string getName() const override;
    double getCalories() const override;
};

