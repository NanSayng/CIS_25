#pragma once
#include <iostream>
#include <string>
#include "user.h"
#include "inputValidation.h"
#include "mealManager.h"
#include "menu.h"
#include "fitnessManager.h"
using namespace std;

void getMenuOption(User& user);
// get user's name
string getValidName();
// get user's age
int getValidAge();
// get user's gender
bool getValidGender();
// ask user's height
double getValidHeight();
// get user's current weight
double getValidCurrWeight();
// get user's goal weight
double getValidGoalWeight();
// get user's fitness goal
int getValidGoal();
// to get user's activity level
int getValidActiveLevel();
void getUserInfo(User& user);

