#include "../include/passenger.hpp"

// Default constructor
Passenger::Passenger() : age(0), seatClass(SeatClass::Economy) {
        std::strcpy(this->name, ""); // Set default empty string
        std::strcpy(this->contact, "");
        std::strcpy(this->passportNumber, "");
        std::strcpy(this->seatNumber, "");
    }

// Constructor
Passenger::Passenger(const char* name, int age, const char* contact,
              const char* passportNumber, SeatClass seatClass, const char* seatNumber)
        : age(age), seatClass(seatClass) {
    std::strcpy(this->name, name);
    std::strcpy(this->contact, contact);
    std::strcpy(this->passportNumber, passportNumber);
    std::strcpy(this->seatNumber, seatNumber);
}
// setter
void Passenger::setName(const char* name) {
    std::strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
}

void Passenger::setAge(int age) {
    this->age = age;
}

void Passenger::setContact(const char* contact) {
    std::strncpy(this->contact, contact, sizeof(this->contact) - 1);
    this->contact[sizeof(this->contact) - 1] = '\0';
}

void Passenger::setPassportNumber(const char* passportNumber) {
    std::strncpy(this->passportNumber, passportNumber, sizeof(this->passportNumber) - 1);
    this->passportNumber[sizeof(this->passportNumber) - 1] = '\0';
}

void Passenger::setSeatNumber(const char* seatNumber) {
    std::strncpy(this->seatNumber, seatNumber, sizeof(this->seatNumber) - 1);
    this->seatNumber[sizeof(this->seatNumber) - 1] = '\0';
}

void Passenger::setSeatClass(SeatClass seatClass) {
    this->seatClass = seatClass;
}


// getter
string Passenger::getName() const { return string(name); }
int Passenger::getAge() const { return age; }
string Passenger::getContact() const { return string(contact); }
string Passenger::getPassportNumber() const { return string(passportNumber); }
string Passenger::getSeatNumber() const{ return string(seatNumber); }
SeatClass Passenger::getSeatClass() const { return seatClass; }
