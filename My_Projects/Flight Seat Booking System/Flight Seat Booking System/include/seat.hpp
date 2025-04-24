#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;

enum class SeatClass {First, Business, Economy};

struct Seat{
    SeatClass seatClass;
    string seatNumber;
    bool isBooked;
};

#endif

