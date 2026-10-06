#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    float marks;
};

vector<Student> students;

void saveStudents() {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.id << " "
             << s.name << " "
             << s.course << " "
             << s.marks << endl;
    }

    file.close();
}

void loadStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.id >> s.name >> s.course >> s.marks) {
        students.push_back(s);
    }

    file.close();
}

void addStudent() {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Course: ";
    cin >> s.course;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    saveStudents();

    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

    cout << "\n----- Student Records -----\n";

    for (const auto& s : students) {
        cout << "ID: " << s.id
             << " | Name: " << s.name
             << " | Course: " << s.course
             << " | Marks: " << s.marks << endl;
    }
}

void searchStudent() {
    int id;

    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Course: " << s.course << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

void updateStudent() {
    int id;

    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto& s : students) {
        if (s.id == id) {
            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Course: ";
            cin >> s.course;

            cout << "Enter New Marks: ";
            cin >> s.marks;

            saveStudents();

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void deleteStudent() {
    int id;

    cout << "Enter Student ID to delete: ";
    cin >> id;

    auto oldSize = students.size();

    students.erase(
        remove_if(
            students.begin(),
            students.end(),
            [id](const Student& s) {
                return s.id == id;
            }
        ),
        students.end()
    );

    if (students.size() < oldSize) {
        saveStudents();
        cout << "Student deleted successfully!\n";
    } else {
        cout << "Student not found!\n";
    }
}

int main() {
    loadStudents();

    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add student\n";
        cout << "2. View students\n";
        cout << "3. Search student\n";
        cout << "4. Update student\n";
        cout << "5. Delete student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "Exiting Student Management System...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
