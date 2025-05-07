#pragma once
#include "user.h"
#include "inputValidation.h"
#include "menu.h"
#include "getUserInfo.h"
#include <iostream>
#include <iomanip>

// to add meals to array
void addMeal(User& user);
// to remove meal and calories from the array
void removeMeals(User& user);
// to show what meals and calories user had added
void trackMeals(User& user);
