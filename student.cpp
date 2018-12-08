#include "student.h"
#include <iostream>

// Constructor: Initializes all member variables using the provided parameters.
Student::Student(std::string studentID, std::string firstName, std::string lastName,
                 std::string emailAddress, int age, int daysToCompleteCourses[],
                 DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName),
      emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    // Copy each element from the input array into the object's array.
    for (int i = 0; i < 3; ++i) {
        this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
    }
}

// Getters return corresponding private member variables.
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int* Student::getDaysToCompleteCourses() { return daysToCompleteCourses; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters update corresponding private member variables.
void Student::setStudentID(std::string ID) { studentID = ID; }
void Student::setFirstName(std::string fName) { firstName = fName; }
void Student::setLastName(std::string lName) { lastName = lName; }
void Student::setEmailAddress(std::string email) { emailAddress = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToCompleteCourses(int days[]) {
    for (int i = 0; i < 3; ++i) {
        daysToCompleteCourses[i] = days[i];
    }
}
void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }

// Print method: Displays all student details in a tab-separated format.
void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Email: " << emailAddress << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysToCompleteCourses[0] << ", " 
              << daysToCompleteCourses[1] << ", " << daysToCompleteCourses[2] << "} ";
    std::cout << "Degree Program: ";
    
    // Print the degree program in a human-readable format.
    switch(degreeProgram) {
        case SECURITY: std::cout << "Security"; break;
        case NETWORK: std::cout << "Network"; break;
        case SOFTWARE: std::cout << "Software"; break;
    }
    std::cout << std::endl;
}
