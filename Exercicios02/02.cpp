#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <algorithm>

const int Num {10}; // Number of patients

// Defining the structures
struct Date {
    int day, month, year;
};

struct Patient {
    std::array<int, 11> cpf;
    std::string name;
    Date birth;
    int age;
};

// Function that receives the date of birth and returns the age.
int calculatesAge(Date today, Date birth) {
    int age {today.year - birth.year};

    if (today.month < birth.month || (today.month == birth.month && today.day < birth.day)) {
        age--;
    }

    return age;
}

int main() {
    std::cout << "\nEnter Patient Data:\n";
    std::array<Patient, Num> patients; // Allocating the structure that stores patients

    // Sets today's date.
    auto now {std::chrono::system_clock::now()};
    auto time {std::chrono::system_clock::to_time_t(now)};
    std::tm today_tm {*std::localtime(&time)};
    Date today {today_tm.tm_mday, today_tm.tm_mon + 1, today_tm.tm_year + 1900};

    // Reading patient data
    for (int i = 0; i < Num; i++) {
        std::cout << "\nPatient " << i + 1 << ":\n";

        // Reading the CPF as a array of integers
        std::string cpfStr;
        std::cout << "CPF: ";
        std::getline(std::cin, cpfStr);
        
        if (cpfStr.size() != 11 || !std::all_of(cpfStr.begin(), cpfStr.end(), ::isdigit)){
            std::cout << "Invalid CPF! Please enter 11 digits.\n";
            i--;
            continue;
        }

        for (int j {0}; j < 11; j++) {
            patients[i].cpf[j] = cpfStr[j] - '0';
        }

        std::cout << "Name: ";
        std::getline(std::cin, patients[i].name);

        std::cout << "Date of birth [dd mm yyyy]: ";
        std::cin >> patients[i].birth.day >> patients[i].birth.month >> patients[i].birth.year;
        std::cin.ignore();
        patients[i].age = calculatesAge(today, patients[i].birth); // Calculates age and stores it in the patient structure.
        std::cout << "\n";
    }

    // Check the oldest age for each patient.
    int older_age {patients[0].age};
    for (Patient p : patients){
        if (p.age > older_age) {
            older_age = p.age;
        }
    }

    // Shows the oldest patient(s)
    std::cout << "\nOlder patient(s): \n";
    for (Patient p : patients) {
        if (p.age == older_age) {
            std::cout << " [ " << p.name << " ] ";
        }
    }

    // It shows all patients with their data and says whether they are older or younger.
    std::cout << "\n\nPatients: \n";
    int i {0};
    for (Patient p : patients) {
        std::cout << "\nPatient " << ++i << ":\n";
        std::cout << "CPF: ";
        for (int j = 0; j < 11; j++) {
            std::cout << p.cpf[j];
        }
        std::cout << "\n";
        std::cout << "Name: " << p.name << "\n";
        std::cout << "Age: " << calculatesAge(today, p.birth) << "\n";

        p.age >= 18 ? std::cout << "Over Eighteen\n" : std::cout << "Under Age\n";
    }

    return 0;
}
