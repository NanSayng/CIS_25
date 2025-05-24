#pragma once
#include <cstring>
#include "seat.hpp"

class Passenger {
private:
    char name[50];
    int age;
    char contact[11];
    char passportNumber[20];
    SeatClass seatClass;
    char seatNumber[10];
public:
    // Default constructor
    Passenger();
    
    // Constructor
    Passenger(const char* name, int age, const char* contact,
              const char* passportNumber, SeatClass seatClass, const char* seatNumber);
    // setter
    void setName(const char* name);
    void setAge(int age);
    void setContact(const char* contact);
    void setPassportNumber(const char* passportNumber);
    void setSeatNumber(const char* seatNumber);
    void setSeatClass(SeatClass seatClass);
    // getter
    string getName() const;
    int getAge() const;
    string getContact() const;
    string getPassportNumber() const;
    string getSeatNumber() const;
    SeatClass getSeatClass() const;
};


