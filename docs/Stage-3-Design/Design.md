# Stage 3 - System Design & Architecture

## 1. System Architecture

The Student Management System is a console-based C++ application.

User
  |
  v
Main Menu
  |
  +--> Add Student
  +--> View Students
  +--> Search Student
  +--> Update Student
  +--> Delete Student
  |
  v
Student Records
  |
  v
students.txt

## 2. Main Components

- Main Menu
- Student Management Module
- Add Student Module
- View Student Module
- Search Student Module
- Update Student Module
- Delete Student Module
- File Storage Module

## 3. Data Structure

The system uses a Student structure containing:

- Student ID
- Student Name
- Course
- Marks

## 4. System Flow

Start
  |
Load Student Records
  |
Display Menu
  |
Select Operation
  |
Perform Operation
  |
Save Changes
  |
Return to Menu
  |
Exit

## 5. Development Environment

- Programming Language: C++
- Operating System: Ubuntu Linux
- Compiler: GNU G++
- Version Control: Git
- Repository: GitHub

## 6. Design Objective

The design provides a simple modular structure that makes the system easy to understand, test and maintain.
