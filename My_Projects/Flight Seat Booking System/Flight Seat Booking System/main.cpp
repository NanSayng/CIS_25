#include <iostream>
#include <filesystem>
#include "include/loadFromSeatsFile.hpp"
#include "include/loadFromPassengersFile.hpp"
#include "include/saveToPassengersFile.hpp"
#include "include/displayMenu.hpp"
#include "utils/getValidChoice.hpp"
#include "include/viewFlightSeats.hpp"
#include "include/bookFlightSeat.hpp"
#include "include/cancelBooking.hpp"
#include "include/viewPassengersList.hpp"
#include "include/exitProgram.hpp"
using namespace std;

int main(){
    string seatsFile = "seats.txt";
    loadFromSeatsFile(seatsFile, seats);
    loadFromPassengersFile(passengers);
    int choice;
    do{
        displayMenu();
        choice = getValidChoice();
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
                viewPassengersList();
                break;
            case 5:
                //exitProgram();
                break;
            default:
                break;
        }
    }while(choice != 5);
    
    return 0;
}

