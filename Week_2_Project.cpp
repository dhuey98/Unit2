#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

// Get student data from a file
void readStudentData(Student students[], int &studentCount) {
    ifstream file("student_data.txt");
    
    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        exit(1);
    }
    
    studentCount = 0;
    while (file >> ws && getline(file, students[studentCount].name)) {
        file >> students[studentCount].age;
        file >> students[studentCount].gpa;
        studentCount++;
    }
    
    file.close();
}

// Function to display all student information
void displayStudents(const Student students[], int studentCount) {
    for (int i = 0; i < studentCount; ++i) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << students[i].gpa << endl;
    }
}

// Function to search for a student by name
void searchStudentByName(const Student students[], int studentCount, const string &name) {
    bool found = false;
    
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].name == name) {
            cout << "Student found:" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "GPA: " << students[i].gpa << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Student named \"" << name << "\" was not found." << endl;
    }
}

// Main function
int main() {
    const int max_students = 100;
    Student students[max_students];
    int studentCount = 0;

    // Get student data
    readStudentData(students, studentCount);

    // Display all of the student information
    cout << "Displaying all students:" << endl;
    displayStudents(students, studentCount);
    cout << endl;

    // Search for a student by name
    string searchName;
    cout << "Enter the name of the student: ";
    getline(cin, searchName);
    searchStudentByName(students, studentCount, searchName);

    return 0;
}