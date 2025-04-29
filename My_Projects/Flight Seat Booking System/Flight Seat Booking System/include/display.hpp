#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "data.hpp"
#include "validateUserInputs.hpp"
#include "booking.hpp"
using namespace std;

void displayMenu();
void viewFlightSeats(string& seatsFile);
void viewPassengersList();
void exitProgram();

