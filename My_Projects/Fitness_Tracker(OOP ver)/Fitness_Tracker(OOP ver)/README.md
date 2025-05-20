[![Build and Test](https://github.com/NanSayng/CIS_25/actions/workflows/ci.yml/badge.svg)](https://github.com/NanSayng/CIS_25/actions/workflows/ci.yml)
## Health and Fitness Tracker (OOP Version)
This is a remake of Project 1, but rewritten in Object-Oriented Programming (OOP) to improve the code structure and make it easier to manage. 
This project is a tracker system that allows users to add meals, add workout, track meals, track workouts, remove meals, and remove workouts, and view their progress to know if they're calorie surplus or deficit based on the informations they have put in. The project also has the unit testing with Google Test.
## Project Overview
Previously, the project was implemented using a procedural and functional approach. But this version applied the core concepts of OOP -
- Classes & Objects  
- Abstraction  
- Encapsulation  
- Inheritance  
- Polymorphism  
- Composition
## Features
- add, view, track the user's meals and workouts
- save the calories and calculate their daily intake calories based on their fitness goal
- unit testing with Google Test (a function test, control flow test, edge case test)
## Technologies Used
- CMake (build system)
- Google Test (unit testing integrated via FetchContent)
## Project Structure
```bash
HealthAndFitnessTracker/
├── include/          # Header files
├── src/              # Implementation files
├── test/             # Google Test unit tests
├── CMakeLists.txt    # Build configuration
├── main.cpp 
