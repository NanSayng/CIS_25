# pragma once
#include <fstream>
#include <iostream>
#include "data.hpp"
using namespace std;

// read from files
void loadFromPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers);
void loadFromSeatsFile(string& seatsFile, map<string, shared_ptr<Seat>>& seats);

// write to files
void saveToPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers);
void saveToSeatsFile();

