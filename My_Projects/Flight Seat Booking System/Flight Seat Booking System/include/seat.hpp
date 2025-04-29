#pragma once
#include <string>
using namespace std;

enum class SeatClass {First, Business, Economy};

struct Seat{
    SeatClass seatClass;
    string seatNumber;
    bool isBooked;
};
