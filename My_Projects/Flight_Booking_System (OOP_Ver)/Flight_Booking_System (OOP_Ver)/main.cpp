#include <iostream>
#include "include/flightBookingSystem.h"
using namespace std;

int main(){
    FlightBookingSystem bookingSystem;
    bookingSystem.loadFromSeatsFile(bookingSystem.getSeatsFile(), bookingSystem.getSeats());
    bookingSystem.loadFromPassengersFile(bookingSystem.getPassengersFile(), bookingSystem.getPassengers());
    bookingSystem.runProgram();
    return 0;
}
