//
//  meal.cpp
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#include "../include/meal.h"

Meal::Meal(const string& name, const double& calories) : Entry(name, calories) {}

string Meal::getName() const{
    return name;
}

double Meal::getCalories() const{
    return calories;
}


