cmake_minimum_required(VERSION 3.30)
project("Fitness Tracker OOP Version")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

include_directories(include utils)

add_executable(fitness_manager main.cpp)
target_link_libraries(fitness_manager PRIVATE fitness_lib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(fitness_lib
   src/entry.cpp
   src/fitnessTracker.cpp
   src/meal.cpp
   src/user.cpp
   src/workout.cpp
   utils/validInput.cpp
)

target_include_directories(fitness_lib PUBLIC include utils)

add_executable(runTests
	test/userInputsTest.cpp
)

target_include_directories(runTests PRIVATE include utils)
target_link_libraries(runTests PRIVATE fitness_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)


