#pragma once
#include "seat.hpp"

struct Passenger{
    char name[50];
    int age;
    char contact[11];
    char passportNumber[20];
    SeatClass seatClass;
    char seatNumber[10];
};


