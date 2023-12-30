#include "02.hpp"

// Number of students to be registered
const int qty {2};

int main(){
    vector<Student> students(qty);

    // Reads students' data
    read_students(students, qty);
    
    // Shows, on the screen, the name of the students with the highest first grade
    highest_g1(students, qty);

    // Shows, on the screen, the student with the highest Grade Point Average
    highest_average(students, qty);

    // Shows on screen students and their situations
    pass_rate(students, qty);

    return 0;
}
