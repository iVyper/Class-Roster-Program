# Class Roster Program

This project is a C++ application that manages a class roster. It allows you to add, remove, and display student records; validate student email addresses; and calculate the average number of days students take to complete courses. The program also supports filtering students by their degree program.

## Project Structure

- **degree.h**  
  Defines an enumerated data type `DegreeProgram` with values for `SECURITY`, `NETWORK`, and `SOFTWARE`.

- **student.h / student.cpp**  
  Contains the `Student` class, which stores information for an individual student, including personal details, course completion times, and the degree program. Includes getters, setters, and a method to print student information.

- **roster.h / roster.cpp**  
  Contains the `Roster` class, which manages an array of `Student` objects. Provides methods to add and remove students, print all student data, print invalid email addresses, calculate average days in courses, and filter students by degree program.

- **main.cpp**  
  The main entry point of the application. It prints course information, creates a `Roster` object, adds students by parsing hardcoded data, and demonstrates various functionalities such as printing student data, validating emails, computing averages, and removing students.

## How to Build and Run

1. **Clone the Repository or Download the Source Files:**

   ```bash
   git clone https://github.com/yourusername/classRosterProgram.git
   cd classRosterProgram

2. **Compile the Program:**

    ```bash
    g++ -std=c++11 main.cpp roster.cpp student.cpp -o classRosterProgram

3. **Run the Executable:**

    ```bash
    ./classRosterProgram

## Features

- **Add Students:** Parse a set of CSV-like strings to add student records to the roster.
- **Remove Students:** Remove a student by their student ID with error handling for invalid IDs.
- **Display Data:** Print all student data, average days in courses, and students by degree program.
- **Email Validation:** Identify and print invalid email addresses using regular expressions.

## License

This project is open-source and available under the MIT License.