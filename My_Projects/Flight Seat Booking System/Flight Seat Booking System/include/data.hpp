#ifndef data_hpp
#define data_hpp
#include <map>
#include <unordered_map>
#include <string>
#include "seat.hpp"
#include "passenger.hpp"
using namespace std;

extern map<string, Seat> seats;
extern unordered_map<string, Passenger> passengers;

#endif /* data_hpp */
