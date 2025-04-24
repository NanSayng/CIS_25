#include <iostream>
#include "include/initializeSeats.hpp"
#include "include/displayMenu.hpp"
#include "utils/getValidChoice.hpp"
#include "include/viewFlightSeats.hpp"
#include "include/bookFlightSeat.hpp"
#include "include/cancelBooking.hpp"
#include "include/exitProgram.hpp"
using namespace std;

int main(){
    initializeSeats();
    string seatsFile = "seats.txt";
    displayMenu();
    int choice = getValidChoice();
    switch(choice){
        case 1:
            viewFlightSeats(seatsFile);
            break;
        case 2:
            bookFlightSeat();
            break;
        case 3:
            cancelBooking();
            break;
        case 4:
            exitProgram();
            break;
        default:
            break;
    }
}
