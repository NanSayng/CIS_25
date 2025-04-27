#ifndef saveToPassengersFile_hpp
#define saveToPassengersFile_hpp
#include <fstream>
#include <iostream>
#include "data.hpp"
using namespace std;

void saveToPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers);

#endif
