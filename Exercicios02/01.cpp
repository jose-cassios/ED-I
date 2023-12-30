#include <iostream>

// Defining the structures
struct Time {
    int hour, minutes, seconds, validated;
};

struct Date {
    int day, month, year, validated;
};

Time *currentTime;
Date *date;

// Function that frees allocated memory
void freeMemory() {
    delete currentTime;
    delete date;
}

int main() {
    // Allocating memory
    currentTime = new Time;
    date = new Date;

    // Reading the data
    std::cout << "Enter the date: ";
    std::cin >> date->day >> date->month >> date->year;
    std::cout << "Enter the time: ";
    std::cin >> currentTime->hour >> currentTime->minutes >> currentTime->seconds;

    // Validating the time
    currentTime->validated = (currentTime->hour >= 0 && currentTime->hour <= 23 &&
                       currentTime->minutes >= 0 && currentTime->minutes <= 59 &&
                       currentTime->seconds >= 0 && currentTime->seconds <= 59) ? 1 : 0;

    // Validating the date
    date->validated = (date->day >= 1 && date->day <= 31 &&
                       date->month >= 1 && date->month <= 12 &&
                       date->year >= 0 && date->year <= 9999) ? 1 : 0;

    // Print validation
    currentTime->validated ? std::cout << "Validated Time!\n" : std::cout << "Invalid Time!\n";
    date->validated ? std::cout << "Validated Date!\n" : std::cout << "Invalid Date!\n";

    // At the end of the program, call the function that frees the allocated memory
    std::atexit(freeMemory);

    return 0;
}
