# mygrep (A simple grep Tool in C++)
This is a C++ command-line tool that mimics the basic functionalities and basic features of how grep works.

## Files Included
- main.cpp (contains the main function and command-line argument handling)
- grep.cpp / grep.hpp (contains helper functions for string matching and file reading)
- logs.txt (Sample txt file to test the program)
- 'mygrep_tutorial.pdf' (step by step explanation and tutorial how the program works)

## Features
- Read txt files line by line
- search for keyword in each line
- '-i' flag: caseInsensitive matching
- '-n' flag: show line numbers that has the keyword in that line

## How to run
```bash
# Run
./mygrep [-i] [-n] <keyword> <filename>

# Example
./mygrep -i -n error logs.txt
