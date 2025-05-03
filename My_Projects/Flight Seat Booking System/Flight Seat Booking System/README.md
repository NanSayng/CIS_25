![Build and Test](https://github.com/NanSayng/CIS_25/actions/workflows/cross-platform-ci.yml/badge.svg)

# Flight Seat Booking System (C++)
This project is an airline seats reservation system that allows user to book, cancel, view seats and view
passengers list. The project also has the unit testing with Google Test.
## Features
- add, view and manage passengers information
- save/update passengers data to binary file from unordered_map
- save/update seats data to text file from map
- Use of 'unique_ptr' and 'shared_ptr' for efficient memory
- unit testing with Google Test
## Technologies Used
- CMake (build system)
- Google Test (unit testing, integrated via FetchContent)
## Project Structure
```bash
task_tracker/
├── include/          # Header files
├── src/              # Implementation files
├── test/             # Google Test unit tests
├── data/             # unordered_map and map
├── passengers.dat    # passengers binary file         
├── seats.txt         # seats text file
├── CMakeLists.txt    # Build configuration
├── main.cpp          
└── .gitignore        # Git ignore rules
