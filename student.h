#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

// The Student class represents an individual student in the roster.
// It holds personal information, academic details, and degree program data.
class Student {
private:
    // Private member variables for storing student information.
    std::string studentID;           // Unique identifier for the student
    std::string firstName;           // Student's first name
    std::string lastName;            // Student's last name
    std::string emailAddress;        // Student's email address
    int age;                         // Student's age
    int daysToCompleteCourses[3];    // Array storing days required to complete three courses
    DegreeProgram degreeProgram;     // Degree program in which the student is enrolled

public:
    // Constructor: Initializes a Student object with all member variables.
    Student(std::string studentID, std::string firstName, std::string lastName,
            std::string emailAddress, int age, int daysToCompleteCourses[],
            DegreeProgram degreeProgram);
    
    // Getters: Return the values of private member variables.
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int* getDaysToCompleteCourses();
    DegreeProgram getDegreeProgram() const;
    
    // Setters: Allow modification of the private member variables.
    void setStudentID(std::string ID);
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setEmailAddress(std::string email);
    void setAge(int age);
    void setDaysToCompleteCourses(int days[]);
    void setDegreeProgram(DegreeProgram dp);
    
    // Print Method: Outputs the student's data to the console in a formatted manner.
    void print() const;
};

#endif // STUDENT_H
