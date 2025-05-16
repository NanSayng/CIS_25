//
//  workout.cpp
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#include "../include/workout.h"

Workout::Workout(const string& name, const double& calories) : Entry(name, calories) {}

string Workout::getName() const{
    return name;
}

double Workout::getCalories() const{
    return calories;
}
