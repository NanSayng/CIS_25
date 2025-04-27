#ifndef loadFromSeatsFile_hpp
#define loadFromSeatsFile_hpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include "seat.hpp"
#include "data.hpp"
using namespace std;

void loadFromSeatsFile(string& seatsFile, map<string, shared_ptr<Seat>>& seats);

#endif
