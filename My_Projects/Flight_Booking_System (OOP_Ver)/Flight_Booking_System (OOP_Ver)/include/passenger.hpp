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
    // setter
    void setName(const char* name) {
        std::strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }

    void setAge(int age) {
        this->age = age;
    }

    void setContact(const char* contact) {
        std::strncpy(this->contact, contact, sizeof(this->contact) - 1);
        this->contact[sizeof(this->contact) - 1] = '\0';
    }

    void setPassportNumber(const char* passportNumber) {
        std::strncpy(this->passportNumber, passportNumber, sizeof(this->passportNumber) - 1);
        this->passportNumber[sizeof(this->passportNumber) - 1] = '\0';
    }

    void setSeatNumber(const char* seatNumber) {
        std::strncpy(this->seatNumber, seatNumber, sizeof(this->seatNumber) - 1);
        this->seatNumber[sizeof(this->seatNumber) - 1] = '\0';
    }
    
    void setSeatClass(SeatClass seatClass) {
        this->seatClass = seatClass;
    }

    
    // getter
    string getName() const { return string(name); }
    int getAge() const { return age; }
    string getContact() const { return string(contact); }
    string getPassportNumber() const { return string(passportNumber); }
    string getSeatNumber() const{ return string(seatNumber); }
    SeatClass getSeatClass() const { return seatClass; }
};


