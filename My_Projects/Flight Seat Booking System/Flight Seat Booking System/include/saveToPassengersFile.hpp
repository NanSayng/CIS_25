#ifndef saveToPassengersFile_hpp
#define saveToPassengersFile_hpp
#include <fstream>
#include <iostream>
#include "data.hpp"
using namespace std;

void saveToPassengersFile(string& filename, unordered_map<string, Passenger>& passengers);

#endif
