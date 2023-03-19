# Student-Teacher Portal

This C program provides basic functionality for a student-teacher portal that allows students to log in and view their marks, and teachers to log in and enter marks for a specific student. The program uses a binary search tree to store user credentials, and each node of the tree stores a username, password, and marks for up to five subjects.

## Features
- Student and teacher login
- Student and teacher signup
- Enter and view marks for students
- Binary search tree for efficient storage and retrieval of user credentials
- Basic input validation and error checking

## Usage
1. Clone the repository: `git clone https://github.com/yashaswiniravuri/Student-Teacher-Portal.git`
2. Compile the program: `gcc main.c -o portal`
3. Run the program: `./portal`

## Functions
- `insert(char username[], char password[])`: inserts a new node into the binary search tree with the given username and password. If the username already exists, the function returns without inserting a new node.
- `search(char username[], char password[], int is_teacher)`: traverses the binary search tree to find the node with the given username and password (if applicable) and returns a pointer to the node. If the user is a teacher and is accessing a student's profile, the function returns the pointer to the student's node without checking the password.
- `insertMarks(struct node *student)`: prompts the teacher to enter marks for each subject for a specific student and updates the student's node with the marks entered.
- `displayMarks(struct node *student)`: displays the marks for each subject for a specific student.

## Improvement Suggestions
- Add more error checking and input validation
- Allow for persistent storage of student and teacher data by adding the ability to store and retrieve data from a file
