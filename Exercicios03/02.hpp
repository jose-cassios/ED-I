#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student structure, stores enrollment, name and grades.
struct Student{
    string enrollment;
    string name;
    float g1, g2, g3;
};

// a) Allows the user to enter the data of qty students.
void read_students(vector<Student> &students, int qty){
    for (int i = 0; i < qty; i++) {
        cout << "Enter the student's school enrollment: ";
        cin >> students[i].enrollment;

        cout << "Enter the student's name: ";
        cin >> students[i].name;

        cout << "Type the n1: ";
        cin >> students[i].g1;

        cout << "Type the n2: ";
        cin >> students[i].g2;

        cout << "Type the n3: ";
        cin >> students[i].g3;

        cout << '\n';
    }
}


// b) Finds the student with the highest score on the first test.
void highest_g1(const vector<Student> &students, int qty){
    float highest = students[0].g1;

    for (int i = 1; i < qty; i++){
        if (students[i].g1 > highest){
            highest = students[i].g1;
        }
    }

    cout << "The student(s) with the highest first grade was: ";
    for (Student student : students){
        if (student.g1 == highest){
            cout << "[ " << student.name << " ] ";
        }
    }
    cout << "\n\n";
}


// c) Finds the student with the highest GPA (Grade Point Average).
void highest_average(const vector<Student> &students, int qty){
    float highestGPA = (students[0].g1 + students[0].g2 + students[0].g3) / 3.0f;
    
    for (int i = 1; i < qty; i++) {
        float currentAverage = (students[i].g1 + students[i].g2 + students[i].g3) / 3.0f;
        if (currentAverage > highestGPA) {
            highestGPA = currentAverage;
        }
    }

    cout << "The student(s) with the highest GPA was: ";
    for (Student student : students) {
        float currentAverage = (student.g1 + student.g2 + student.g3) / 3.0f;
        if (currentAverage == highestGPA) {
            cout << "[ " << student.name << " ] ";
        }
    }
    cout << "\n\n";
}

// d) Informs whether the student passed or failed.
void pass_rate(const vector<Student> &students, int qty) {
    for (Student student : students) {
        float media = (student.g1 + student.g2 + student.g3) / 3.0f;
        if (media >= 7.0f) {
            cout << "[ " << student.name << " ] - Passed\n";
        } else {
            cout << "[ " << student.name << " ] - Failed\n";
        }
    }
    cout << "\n\n";
}
