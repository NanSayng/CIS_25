#include "../include/flightBookingSystem.h"
using namespace std;

void FlightBookingSystem::displayMenu(){
    cout << "\n--- Welcome to Nan's Airline ---\n\n";
    cout << "1.\tView flight seats\n";
    cout << "2.\tBook a seat\n";
    cout << "3.\tCancel booking\n";
    cout << "4.\tView passengers list\n";
    cout << "5.\tExit\n";
}

int FlightBookingSystem::getMenuOption(){
        string input;
        int choice;
    while(true){
        cout << "Enter your choice [1-8]: ";
        cin >> input;
        if(input.empty() || !isValidChoice(input)){
            cout << "Invalid choice.\n";
        }else{
            break;
        }
    }
    choice = stoi(input);
    return choice;
}

void FlightBookingSystem::loadFromPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers){
    try{
        fstream file(passengersFile, ios::in | ios::binary);
        if(!file.is_open()){
            throw runtime_error("Error opening the passengers file.");
            return;
        }
        Passenger passenger;
        while(file.read(reinterpret_cast<char*>(&passenger), sizeof(Passenger))){
            passengers[passenger.getPassportNumber()] = make_unique<Passenger>(passenger);
        }
        file.close();
    }
    catch(const exception& e){
        cout << "Exception: " << e.what() << endl;
    }
}

void FlightBookingSystem::loadFromSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats){
    try{
        fstream file(seatsFile, ios::in);
        if(!file.is_open()){
            throw runtime_error("Error opening the seats file.\n");
            return;
        }
        string seatNum;
        string seatClassStr;
        bool isBooked;
        
        while(file >> seatNum >> seatClassStr >> isBooked){
            SeatClass seatClass;
            if(seatClassStr == "First"){
                seatClass = SeatClass::First;
            }else if(seatClassStr == "Business"){
                seatClass = SeatClass::Business;
            }else{
                seatClass = SeatClass::Economy;
            }
            if(seatClassStr == "First") {
                auto seat = make_shared<FirstClassSeat>(seatNum);
                seat->setBookingStatus(isBooked);
                seats[seatNum] = seat;
            } else if(seatClassStr == "Business") {
                auto seat = make_shared<BusinessClassSeat>(seatNum);
                seat->setBookingStatus(isBooked);
                seats[seatNum] = seat;
            } else {
                auto seat = make_shared<EconomyClassSeat>(seatNum);
                seat->setBookingStatus(isBooked);
                seats[seatNum] = seat;
            }
        }
        file.close();
    }
    catch(const exception& e){
        cout << "Exception: " << e.what() << endl;
    }
}

// update to passengersFile
void FlightBookingSystem::saveToPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers){
    try{
        fstream file(passengersFile, ios::out | ios::binary);
        if(!file.is_open()){
            throw runtime_error("Error opening the passengers file.\n");
            return;
        }
        
        for(const auto& passengerPair : passengers){
            const Passenger& p = *(passengerPair.second);
            file.write(reinterpret_cast<const char*>(&p), sizeof(Passenger));
        }
        file.close();
    }
    catch(const exception& e){
        cout << "Exception: " << e.what() << endl;
    }
}

// update to seats file
void FlightBookingSystem::saveToSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats){
    try{
        fstream file(seatsFile, ios::out);
        if(!file.is_open()){
            throw runtime_error("Error opening the seats file.");
            return;
        }
        for(auto& seatPair : seats){
            if(seatPair.second->getSeatClass() == SeatClass::First){
                file << seatPair.second->getSeatInfo() << endl;
            }
        }
        for(auto& seatPair: seats){
            if(seatPair.second->getSeatClass() == SeatClass::Business){
                file << seatPair.second->getSeatInfo() << endl;
            }
        }
        for(auto& seatPair: seats){
            if(seatPair.second->getSeatClass() == SeatClass::Economy){
                file << seatPair.second->getSeatInfo() << endl;
            }
        }
        file.close();
    }
    catch(const exception& e){
        cout << "Exception: " << e.what() << endl;
    }
}

void FlightBookingSystem::viewFlightSeats(){
    cout << "\nAvailable Seats: \n";
        cout << "\nFirst Class: \n";
        for(const auto& seatPair : seats){
            if(seatPair.second->getSeatClass() == SeatClass::First){
                if(!seatPair.second->getBookingStatus()){
                    cout << "[" << seatPair.first << "] Available  ";
                }else{
                    cout << "[" << seatPair.first << "] Booked  ";
                }
            }
        }
        cout << endl;
        cout << "\nBusiness Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->getSeatClass() == SeatClass::Business){
                if(!seatPair.second->getBookingStatus()){
                    cout << "[" << seatPair.first << "] Available  ";
                }else{
                    cout << "[" << seatPair.first << "] Booked  ";
                }
            }
        }
        cout << endl;
        cout << "\nEconomy Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->getSeatClass() == SeatClass::Economy){
                if(!seatPair.second->getBookingStatus()){
                    cout << "[" << seatPair.first << "] Available  ";
                }else{
                    cout << "[" << seatPair.first << "] Booked  ";
                }
            }
        }
        cout << endl;
}

void FlightBookingSystem::viewPassengersList(){
    int num = 1;
    cout << "\nPassengers list: \n";
    if(!passengers.empty()){
        for(auto& passengerPair: passengers){
            // dereference unique_ptr to access each Passenger object
            auto& passenger = *passengerPair.second;
            // display passenger information
            cout << num << ". " << passenger.getName() << " | Age: " << passenger.getAge() << " | Phone: " << passenger.getContact() << " | Passport: " << passenger.getPassportNumber() << " | Seat: " << passenger.getSeatNumber() ;
            if(passenger.getSeatClass() == SeatClass::First){
                cout << " (First class)\n";
            }else if(passenger.getSeatClass() == SeatClass::Business){
                cout << " (Business class)\n";
            }else{
                cout << " (Economy class)\n";
            }
            num++;
        }
    }else{
        cout << "There's no passengers to view.\n";
    }
}

void FlightBookingSystem::bookFlightSeat() {
    try{
        Passenger newPassenger;
        cout << "\nBooking a Seat...\n\n";
        int choice;
        
        string name, contact, passport, seatNumber;
        int age;
        
        // get valid name
        while (true) {
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            if (name.empty() || !isValidName(name)) {
                cout << "Invalid name.\n";
            } else {
                newPassenger.setName(name.c_str());
                break;
            }
        }
        
        // get valid age
        while (true) {
            cout << "Enter age: ";
            cin >> age;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid age.\n";
            } else if (age < 12) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Under the age of 12 years old cannot book a flight.\n";
            } else if (age > 100) {
                cout << "Too old to book the flight.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                newPassenger.setAge(age);
                break;
            }
        }
        
        // get valid contact number
        while (true) {
            cout << "Enter phone number (510*******): ";
            getline(cin, contact);
            if (contact.empty() || !isValidContact(contact)) {
                cout << "Invalid contact. Please enter 10 digits number.\n";
            } else {
                newPassenger.setContact(contact.c_str());
                break;
            }
        }
        
        // get valid passport number
        while (true) {
            cout << "Enter passport number (e.g., A123456): ";
            getline(cin, passport);
            if (passport.empty() || !isValidPassNum(passport)) {
                cout << "Invalid passport number. Enter length of 6 to 9.\n";
            } else {
                newPassenger.setPassportNumber(passport.c_str());
                break;
            }
        }
        
        // Select seat class
        cout << "\n\nSelect seat class:\n";
        cout << "1.\tFirst Class\n";
        cout << "2.\tBusiness Class\n";
        cout << "3.\tEconomy Class\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            newPassenger.setSeatClass(SeatClass::First);
        } else if (choice == 2) {
            newPassenger.setSeatClass(SeatClass::Business);
        } else {
            newPassenger.setSeatClass(SeatClass::Economy);
        }
        
        cin.ignore();
        
        // get valid seat number
        while (true) {
            if(newPassenger.getSeatClass() == SeatClass::First){
                cout << "\n\nEnter seat number to book (1A - 5A): ";
            }else if(newPassenger.getSeatClass() == SeatClass::Business){
                cout << "\n\nEnter seat number to book (1B - 5B): ";
            }else{
                cout << "\n\nEnter seat number to book (1C - 5C): ";
            }
            getline(cin, seatNumber);
            if (seatNumber.empty() || !isValidSeatNum(seatNumber)) {
                cout << "Invalid seat number. Please try again.\n";
            } else {
                newPassenger.setSeatNumber(seatNumber.c_str());
                break;
            }
        }
        
        // check and book the seat
        string seatKey = newPassenger.getSeatNumber();
        if (seats.find(seatKey) != seats.end()) {
            if (!seats[seatKey]->getBookingStatus() &&
                seats[seatKey]->getSeatClass() == newPassenger.getSeatClass()) {
                seats[seatKey]->setBookingStatus(true);
                cout << "\nSeat " << seatKey << " has been successfully booked for "
                << newPassenger.getName() << endl;
            }else{
                if(seats[seatKey]->getSeatClass() != newPassenger.getSeatClass()){
                    throw logic_error("Seat class does not match passenger choice.\n");
                }
                if(seats[seatKey]->getBookingStatus()){
                    throw logic_error("Seat is already booked.\n");
                }
            }
        } else {
                throw invalid_argument("Invalid seat number.\n");
        }
        
        // save info to passengers map
        passengers[newPassenger.getPassportNumber()] = make_unique<Passenger>(newPassenger);
        
        // update files
        saveToSeatsFile(getSeatsFile(), getSeats());
        saveToPassengersFile(getPassengersFile(), getPassengers());
    }
    catch(const exception& e){
        cout << "Booking failed: " << e.what() << endl;
    }
}

void FlightBookingSystem::cancelBooking(){
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
    auto& passengers = getPassengers();
    auto it = passengers.find(passportNum);
    if(it != passengers.end() && name == (*it).second->getName()){
        cout << "Booking found: Seat " << (*it).second->getSeatNumber() << endl;
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
                if(seatPair.second->getSeatNumber() == (*it).second->getSeatNumber()){
                    seatPair.second->setBookingStatus(0);
                    // upgrade seats file
                    saveToSeatsFile(getSeatsFile(), getSeats());
                    // remove passenger from unordered_map
                    passengers.erase(passportNum);
                    // upgrade passengers file
                    saveToPassengersFile("passengers.dat", passengers);
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
    }else if(it != passengers.end() && name != (*it).second->getName()){
        cout << "\nName and passport number doesn't match.\n";
    }else{
        cout << "\nNo booking found under that name and passport number.\n";
    }
};

void FlightBookingSystem::exitProgram(){
    string input;
    while(true){
        cout << "\nAre you sure you want to exit? (y/n): ";
        cin >> input;
        if(input.empty() || !isValidChar(input)){
            cout << "Invalid input.\n";
        }else{
            break;
        }
    }
    if(input == "y" || input == "Y"){
        cout << "\nI hope you have a wonderful day. Bye!\n";
        exit(0);
    }else{
        runProgram();
    }
    cout << endl;
}

void FlightBookingSystem::runProgram(){
    int choice;
    do{
        displayMenu();
        choice = getMenuOption();
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






