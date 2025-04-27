#ifndef loadFromPassengersFile_hpp
#define loadFromPassengersFile_hpp
#include "data.hpp"
#include <fstream>
#include <iostream>
using namespace std;

void loadFromPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers);

#endif
