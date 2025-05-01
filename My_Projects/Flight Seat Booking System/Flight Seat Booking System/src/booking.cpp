#include "../include/booking.hpp"

void bookFlightSeat(){
    Passenger newPassenger;
    cout << "\nBooking a Seat...\n\n";
    int choice;
    // get valid name
    while(true){
        cout << "Enter passenger name: ";
        cin.ignore();
        cin.getline(newPassenger.name, sizeof(newPassenger.name));
        // convert from char to string to check validation
        string nameStr(newPassenger.name);
        if(nameStr.empty() || !isValidName(nameStr)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    // get valid age
    while(true){
        cout << "Enter age: ";
        cin >> newPassenger.age;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter valid age.\n";
        }else if(newPassenger.age < 12){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Under the age of 12 years old cannot book a flight.\n";
        }else if(newPassenger.age > 100){
            cout << "Too old to book the flight.\n";
        }else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    // get valid contact number
    while(true){
        cout << "Enter phone number (510*******): ";
        cin.getline(newPassenger.contact, sizeof(newPassenger.contact));
        // convert from char to string to check validation
        string contactStr(newPassenger.contact);
        if(contactStr.empty() || !isValidContact(contactStr)){
            cout << "Invalid contact. Please enter 10 digits number.\n";
        }else{
            break;
        }
    }
    // get valid passport number
    while(true){
        cout << "Enter passport number (e.g, A123456): ";
        cin.getline(newPassenger.passportNumber, sizeof(newPassenger.passportNumber));
        // convert from char to string to check validation
        string passportStr(newPassenger.passportNumber);
        if(passportStr.empty() || !isValidPassNum(passportStr)){
            cout << "Invalid passport number. Enter length of 6 to 9.\n";
        }else{
            break;
        }
    }
    cout << "\n\nSelect seat class:\n";
    cout << "1.\tFirst Class\n";
    cout << "2.\tBusiness Class\n";
    cout << "3.\tEconomy Class\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    
    if(choice == 1){
        newPassenger.seatClass = SeatClass::First;
        cout << "\nAvailable seats in First Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::First && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 2){
        newPassenger.seatClass = SeatClass::Business;
        cout << "\nAvailable seats in Business Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::Business && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 3){
        newPassenger.seatClass = SeatClass::Economy;
        cout << "\nAvailable seats in Economy Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::Economy && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }
    cin.ignore();
    while(true){
        // get valid seat number
        while(true){
            cout << "\n\nEnter seat number to book (1A - 5C): ";
            cin.getline(newPassenger.seatNumber, sizeof(newPassenger.seatNumber));
            // convert from char to string to check validation
            string seatNumStr(newPassenger.seatNumber);
            if(seatNumStr.empty() || !isValidSeatNum(seatNumStr)){
                cout << "Invalid seat number. Please try agin.\n";
            }else{
                break;
            }
        }
        if(seats.find(newPassenger.seatNumber) != seats.end()){
            if(!seats[newPassenger.seatNumber]->isBooked && seats[newPassenger.seatNumber]->seatClass == newPassenger.seatClass){
                seats[newPassenger.seatNumber]->isBooked = 1;
                cout << "\nSeat " << newPassenger.seatNumber << " has been successfully booked for " << newPassenger.name << endl;
                break;
            }else{
                cout << "Seat " << newPassenger.seatNumber << " is already booked.\n";
            }
        }else{
            cout << "\nInvalid seat number.\n";
        }
    }
    // save info to passengers map
    passengers[newPassenger.passportNumber] = make_unique<Passenger>(newPassenger);
    // update seats.txt file
    saveToSeatsFile(seats);
    // update passengers.dat file
    saveToPassengersFile(passengers);
}

void cancelBooking(){
    string name, passportNum, input;
    // get valid name
    while(true){
        cout << "Enter passenger name: ";
        cin.ignore();
        getline(cin, name);
        if(name.empty() || !isValidName(name)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    // get valid passport number
    while(true){
        cout << "Enter passport number: ";
        cin >> passportNum;
        if(passportNum.empty() || !isValidPassNum(passportNum)){
            cout << "Invalid passport number. Enter length of 6 to 9.\n";
        }else{
            break;
        }
    }
    auto it = passengers.find(passportNum);
    if(it != passengers.end() && name == (*it).second->name){
        cout << "Booking found: Seat " << (*it).second->seatNumber << endl;
        // check user input
        while(true){
            cout << "Are you sure you want to cancel this booking? (y/n): ";
            cin >> input;
            if(input.empty() || !isValidChar(input)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input == "y" || input == "Y"){
            for(auto& seatPair : seats){
                if(seatPair.second->seatNumber == (*it).second->seatNumber){
                    seatPair.second->isBooked = 0;
                    // upgrade seats file
                    saveToSeatsFile(seats);
                    // remove passenger from unordered_map
                    passengers.erase(passportNum);
                    // upgrade passengers file
                    saveToPassengersFile(passengers);
                    break;
                }
            }
            cout << "\nBooking for " << name << " has been cancelled successfully.\n";
        }else{
            int choice;
            do{
                string seatsFile = "seats.txt";
                displayMenu();
                // get valid choice
                while(true){
                    cout << "Enter your choice (1-5): ";
                    cin >> choice;
                    string choiceStr = to_string(choice);
                    if(choiceStr.empty() || !isValidChoice(choiceStr)){
                        cout << "Invalid choice.\n";
                    }else{
                        break;
                    }
                }
                switch(choice){
                    case 1:
                        viewFlightSeats();
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
                        exitProgram();
                        break;
                    default:
                        break;
                }
            }while(choice != 5);
        }
    }else if(it != passengers.end() && name != (*it).second->name){
        cout << "\nName and passport number doesn't match.\n";
    }else{
        cout << "\nNo booking found under that name and passport number.\n";
    }
};

