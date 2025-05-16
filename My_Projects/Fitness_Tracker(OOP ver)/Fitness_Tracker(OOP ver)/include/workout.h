//
//  workout.h
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#pragma once
#include "entry.h"

class Workout:public Entry{
public:
    Workout() {}; // default
    Workout(const string& name, const double& calories);
    string getName() const override;
    double getCalories() const override;
};
