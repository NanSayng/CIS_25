cmake_minimum_required(VERSION 3.30)
project("Flight Seat Booking System OOP Ver")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Use static runtime for Visual Studio on Windows
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Include headers from include/
include_directories(include)

# Main executable
add_executable(flight_seat_manager main.cpp)
target_link_libraries(flight_seat_manager PRIVATE flight_seat_lib)

# GoogleTest Setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Prevent GoogleTest from overriding MSVC settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing support
enable_testing()

add_library(flight_seat_lib
    src/flightBookingSystem.cpp
    src/passenger.cpp
    src/seat.cpp
    src/validateUserInputs.cpp
)

target_include_directories(flight_seat_lib PUBLIC include)

# Test executable
add_executable(runTests
   test/test_validation.cpp
   src/validateUserInputs.cpp
)

target_include_directories(runTests PRIVATE include)
target_link_libraries(runTests PRIVATE flight_seat_lib gtest_main)

# Register tests
include(GoogleTest)
gtest_discover_tests(runTests)
