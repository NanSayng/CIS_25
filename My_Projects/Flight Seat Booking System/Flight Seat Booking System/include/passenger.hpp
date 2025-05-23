#pragma once
#include <cstring>
#include "seat.hpp"

struct Passenger {
    char name[50];
    int age;
    char contact[11];
    char passportNumber[20];
    SeatClass seatClass;
    char seatNumber[10];
    
    // Default constructor
        Passenger() : age(0), seatClass(SeatClass::Economy) {
            std::strcpy(this->name, ""); // Set default empty string
            std::strcpy(this->contact, "");
            std::strcpy(this->passportNumber, "");
            std::strcpy(this->seatNumber, "");
        }
    
    // Constructor
    Passenger(const char* name, int age, const char* contact,
                  const char* passportNumber, SeatClass seatClass, const char* seatNumber)
            : age(age), seatClass(seatClass) {
        std::strcpy(this->name, name);
        std::strcpy(this->contact, contact);
        std::strcpy(this->passportNumber, passportNumber);
        std::strcpy(this->seatNumber, seatNumber);
    }
};


