#ifndef data_hpp
#define data_hpp
#include <map>
#include <unordered_map>
#include <memory>
#include <string>
#include "seat.hpp"
#include "passenger.hpp"
using namespace std;

extern map<string, shared_ptr<Seat>> seats;
extern unordered_map<string, unique_ptr<Passenger>> passengers;

#endif /* data_hpp */
