//
//  user.h
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#pragma once
#include <string>
#include <stdexcept>
#include "enum.h"
#include "../utils/validInput.hpp"
using namespace std;

class User{
private:
    string name;
    int age;
    Gender gender;
    double height;
    double currentWeight;
    double goalWeight;
    FitnessGoal fitnessGoal;
    ActivityLevel activityLevel;
public:
    // default constructor
    User();
    // getter
    string getUsername();
    int getUserAge();
    Gender getUserGender();
    double getUserHeight();
    double getUserCurrWeight();
    double getUserGoalWeight();
    FitnessGoal getUserFitnessGoal();
    ActivityLevel getUserActivityLevel();
    
    void getUserInfo();
    double calculateBMR() const;
    double calculateDailyCalorie(const double& BMR) const;
    ~User();
};
