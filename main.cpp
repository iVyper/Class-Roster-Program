#include "roster.h"
#include <iostream>
#include <sstream>
#include <vector>

// Function prototype for parsing student data and adding them to the roster.
void addStudents(Roster& classRoster);

int main() {
    // 1. Print course information (customize as needed)
    std::cout << "Scripting and Programming - Applications\n";
    std::cout << "C++\n";
    std::cout << "010810124\n";
    std::cout << "Ivis Perdomo\n\n";

    // 2. Create an instance of the Roster class to manage student records.
    Roster classRoster;

    // 3. Parse student data and add each student to the roster.
    addStudents(classRoster);

    // 4. Print all student data to the console.
    classRoster.printAll();
    
    // 5. Validate and print any invalid email addresses.
    classRoster.printInvalidEmails();

    // 6. For each student, calculate and print the average days in course.
    for (int i = 0; i <= classRoster.getLastIndex(); ++i) {
        std::string studentID = classRoster.getStudentIDAt(i);
        classRoster.printAverageDaysInCourse(studentID);
    }

    // 7. Print student data filtered by degree program SOFTWARE.
    classRoster.printByDegreeProgram(SOFTWARE);

    // 8. Remove a student by ID and print updated roster to verify removal.
    classRoster.remove("A3");
    classRoster.printAll();

    // 9. Attempt to remove the same student again to demonstrate error handling.
    classRoster.remove("A3");

    // Destructor of Roster automatically cleans up allocated memory.
    return 0;
}

// Parses a predefined list of student data strings and adds them to the roster.
void addStudents(Roster& classRoster) {
    // Array of student data strings in CSV format.
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ivis,Perdomo,perdomoiv2@gmail.com,24,30,35,40,SOFTWARE"
    };

    // Process each student data string.
    for (const std::string& data : studentData) {
        std::vector<std::string> parts;
        std::stringstream ss(data);
        std::string part;
        // Split the string by commas and store each part.
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }

        // Parse days to complete courses (stored at positions 5, 6, and 7).
        int daysArray[3] = { std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]) };
        // Determine the degree program based on the final part of the data.
        DegreeProgram degreeProgram = (parts[8] == "SECURITY") ? SECURITY : (parts[8] == "NETWORK") ? NETWORK : SOFTWARE;

        // Add the student to the roster using the parsed values.
        classRoster.add(parts[0], parts[1], parts[2], parts[3],
                        std::stoi(parts[4]), daysArray[0], daysArray[1], daysArray[2],
                        degreeProgram);
    }
}
