cmake_minimum_required(VERSION 3.30)

project(HealthAndFitnessTracker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)

add_executable(HealthAndFitnessTracker
    main.cpp
    src/fitnessManager.cpp
    src/input_validation.cpp
    src/mealManager.cpp
    src/menu.cpp
    src/user.cpp
)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(runTests
    test/test_tracker.cpp
    src/fitnessManager.cpp
)

target_include_directories(runTests PRIVATE include)
target_link_libraries(runTests PRIVATE gtest_main)
 
include(GoogleTest)
gtest_discover_tests(runTests)
