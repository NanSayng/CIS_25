//
//  entry.cpp
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#include "../include/entry.h"

Entry::Entry() : name("unknown"), calories(0.0) {}

Entry::Entry(const string& name, const double& calories){
    setName(name);
    setCalories(calories);
}

void Entry::setName(const string& name){
    this->name = name;
}

void Entry::setCalories(const double& calories){
    if(calories <= 0){
        throw std::invalid_argument("The calories can't be zero or negative.\n");
    }
    this->calories = calories;
}

string Entry::getName() const{
    return name;
}

double Entry::getCalories() const{
    return calories;
}




