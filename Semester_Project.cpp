#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_TEACHERS = 50;
const int MAX_COURSES = 20;

struct Student {
    string name;
    int age;
    float gpa;
};

struct Teacher {
    string name;
    string subject;
};

struct Course {
    string name;
    string subject;
};

struct Attendance {
    string studentName;
    int day;
    int month;
    int year;
};

Student students[MAX_STUDENTS];
int numStudents = 0;

Teacher teachers[MAX_TEACHERS];
int numTeachers = 0;

Course courses[MAX_COURSES];
int numCourses = 0;

Attendance attendanceRecords[MAX_STUDENTS];
int numAttendanceRecords = 0;

void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter student name: ";
        cin >> students[numStudents].name;
        cout << "Enter student age: ";
        cin >> students[numStudents].age;
        cout << "Enter student GPA: ";
        cin >> students[numStudents].gpa;
        numStudents++;
        cout << "Student added successfully." << endl;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

void listStudents() {
    cout << "List of Students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << "\tAge: " << students[i].age << "\tGPA: " << students[i].gpa << endl;
    }
}

// Similar functions for adding, listing, and managing teachers and courses

void markAttendance() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].name == studentName) {
            found = true;
            attendanceRecords[numAttendanceRecords].studentName = studentName;
            cout << "Enter day, month, and year (separated by spaces): ";
            cin >> attendanceRecords[numAttendanceRecords].day >> attendanceRecords[numAttendanceRecords].month >> attendanceRecords[numAttendanceRecords].year;
            numAttendanceRecords++;
            cout << "Attendance marked." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void viewAttendance() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    cout << "Attendance for " << studentName << ":" << endl;
    for (int i = 0; i < numAttendanceRecords; i++) {
        if (attendanceRecords[i].studentName == studentName) {
            cout << "Date: " << attendanceRecords[i].day << "/" << attendanceRecords[i].month << "/" << attendanceRecords[i].year << endl;
        }
    }
}

int main() {
    while (true) {
        cout << "School Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. List Students" << endl;
        cout << "3. Add Teacher" << endl;
        cout << "4. List Teachers" << endl;
        cout << "5. Add Course" << endl;
        cout << "6. List Courses" << endl;
        cout << "7. Mark Attendance" << endl;
        cout << "8. View Attendance" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            // Implement similar cases for other functionalities
            case 9:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

