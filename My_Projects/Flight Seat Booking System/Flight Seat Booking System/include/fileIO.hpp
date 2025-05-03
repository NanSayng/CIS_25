# pragma once
#include <fstream>
#include <iostream>
#include "data.hpp"
using namespace std;

// read from files
void loadFromPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers);
void loadFromSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats);

// write to files
void saveToPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers);
void saveToSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats);

