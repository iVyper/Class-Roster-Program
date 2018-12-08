#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

// The Roster class manages an array of Student objects.
// It provides methods to add, remove, and print student information,
// as well as validate email addresses and calculate average days in courses.
class Roster {
private:
    Student* classRosterArray[5]; // Fixed-size array for storing Student pointers.
    int lastIndex = -1;           // Tracks the last index used in the array.

public:
    Roster();                   // Constructor: Initializes the array.
    ~Roster();                  // Destructor: Frees dynamically allocated memory.

    // Adds a student to the roster with the provided details.
    void add(std::string studentID, std::string firstName, std::string lastName,
             std::string emailAddress, int age, int daysInCourse1,
             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Removes a student from the roster by their student ID.
    void remove(std::string studentID);

    // Prints information for all students in the roster.
    void printAll() const;

    // Calculates and prints the average number of days a student takes to complete courses.
    void printAverageDaysInCourse(std::string studentID) const;

    // Validates student email addresses and prints any that are invalid.
    void printInvalidEmails() const;

    // Prints information for students enrolled in a specified degree program.
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // Returns the index of the last student in the roster.
    int getLastIndex() const;

    // Retrieves the student ID at a given index in the roster.
    std::string getStudentIDAt(int index) const;
};

#endif // ROSTER_H
