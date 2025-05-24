#include "../include/seat.hpp"

Seat::Seat(SeatClass seatClass, const string& seatNumber, bool isBooked)
: seatClass(seatClass), seatNumber(seatNumber), isBooked(isBooked) {}

// setter
void Seat::setSeatNumber(const string& newSeatNumber) { seatNumber = newSeatNumber; }
void Seat::setSeatClass(SeatClass newSeatClass) { seatClass = newSeatClass; }
void Seat::setBookingStatus(bool booked) { isBooked = booked; }
// getter
bool Seat::getBookingStatus() const { return isBooked; }
SeatClass Seat::getSeatClass() const { return seatClass; }
string Seat::getSeatNumber() const { return seatNumber; }

// Polymorphism
string Seat::getSeatInfo() const{
    return seatNumber + " First " + (isBooked ? "1" : "0");
}

// First class
FirstClassSeat::FirstClassSeat(const string& num) : Seat(SeatClass::First, num, false) {}
string FirstClassSeat::getSeatInfo() const{
    return seatNumber + " First " + (isBooked ? "1" : "0");
}

// Business class
BusinessClassSeat::BusinessClassSeat(const string& num) : Seat(SeatClass::Business, num, false) {}
string BusinessClassSeat::getSeatInfo() const{
    return seatNumber + " Business " + (isBooked ? "1" : "0");
}

// Economy class
EconomyClassSeat::EconomyClassSeat(const string& num) : Seat(SeatClass::Economy, num, false) {}
string EconomyClassSeat::getSeatInfo() const{
    return seatNumber + " Economy " + (isBooked ? "1" : "0");
}


