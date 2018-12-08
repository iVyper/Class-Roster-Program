#include "roster.h"
#include <iostream>
#include <string>
#include <regex> // For validating email addresses

// Constructor: Initializes all pointers in classRosterArray to nullptr.
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        this->classRosterArray[i] = nullptr;
    }
    this->lastIndex = -1;
}

// Destructor: Deletes all Student objects to free memory.
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete this->classRosterArray[i];
        this->classRosterArray[i] = nullptr;
    }
}

// Adds a student to the roster.
// Increments lastIndex and creates a new Student object with the provided data.
void Roster::add(std::string studentID, std::string firstName, std::string lastName,
                 std::string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName,
                                                 emailAddress, age, days, degreeProgram);
}

// Removes a student from the roster by student ID.
// If found, deletes the student object and replaces it with the last student in the array.
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex]; // Replace with last element
            lastIndex--; // Decrement lastIndex since one student is removed
            std::cout << "Student " << studentID << " removed from the roster.\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found.\n";
    }
}

// Prints all student data by calling the print() method of each Student.
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

// Prints the average days in course for a student identified by studentID.
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysToCompleteCourses();
            std::cout << "Average days in course for student ID " << studentID << ": "
                      << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
    std::cout << "Student ID " << studentID << " not found.\n";
}

// Validates each student's email address using a regex pattern.
// Prints emails that do not match the standard email format.
void Roster::printInvalidEmails() const {
    std::regex emailPattern("(\\w+)(\\.\\w+)*@(\\w+)(\\.\\w+)+");
    std::cout << "Invalid emails:\n";
    for (int i = 0; i <= lastIndex; i++) {
        if (!std::regex_match(classRosterArray[i]->getEmailAddress(), emailPattern)) {
            std::cout << classRosterArray[i]->getEmailAddress() << std::endl;
        }
    }
}

// Prints all students enrolled in a specific degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Returns the last index used in the classRosterArray.
int Roster::getLastIndex() const {
    return lastIndex;
}

// Returns the student ID at the specified index if within bounds.
std::string Roster::getStudentIDAt(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index]->getStudentID();
    } else {
        std::cerr << "Error: Index " << index << " out of bounds.\n";
        return "";
    }
}
