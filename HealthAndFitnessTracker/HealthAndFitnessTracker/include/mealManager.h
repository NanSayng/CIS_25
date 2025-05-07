#pragma once
#include "user.h"
#include "input_validation.h"
#include "menu.h"
#include <iostream>
using namespace std;

// to add meals to array
void addMeal(User& user);
// to remove meal and calories from the array
void removeMeals(User& user);
// to show what meals and calories user had added
void trackMeals(User& user);

