#include <iostream>
#include <string>
using namespace std;


struct Subject {
    string subjectName;
    int credit;
    float mark;
    char grade;
};

struct Student {
    string name;
    int age;
    float cpa;
    Subject subjects[5];
    int subjectCount;
};

char calculateGrade(float mark) {
    if (mark >= 85) return 'A';
    else if (mark >= 75) return 'B';
    else if (mark >= 65) return 'C';
    else if (mark >= 50) return 'D';
    else return 'F';
}

void insertSubjects(Student &s) {
    cout << "Enter number of subjects (max 5): ";
    cin >> s.subjectCount;

    while (s.subjectCount < 1 || s.subjectCount > 5) {
        cout << "Invalid. Please enter between 1 to 5: ";
        cin >> s.subjectCount;
    }

    for (int i = 0; i < s.subjectCount; i++) {
        cout << "\nSubject " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, s.subjects[i].subjectName);
        cout << "Credit hour: ";
        cin >> s.subjects[i].credit;

        do {
            cout << "Mark (0 - 100): ";
            cin >> s.subjects[i].mark;
            if (s.subjects[i].mark < 0 || s.subjects[i].mark > 100)
                cout << "Invalid mark! Please enter between 0 and 100.\n";
        } while (s.subjects[i].mark < 0 || s.subjects[i].mark > 100);

        s.subjects[i].grade = calculateGrade(s.subjects[i].mark);
    }
}

void displayStudent(const Student &s) {
    cout << "\nName: " << s.name;
    cout << "\nAge: " << s.age;
    cout << "\nCPA: " << s.cpa;
    cout << "\nSubjects:\n";

    for (int i = 0; i < s.subjectCount; i++) {
        cout << "  " << i + 1 << ". " << s.subjects[i].subjectName
             << " | Credit: " << s.subjects[i].credit
             << " | Mark: " << s.subjects[i].mark
             << " | Grade: " << s.subjects[i].grade << endl;
    }
}

void insertStudents(Student students[], int &studentCount) {
    cout << "Enter number of students (max 10): ";
    cin >> studentCount;

    while (studentCount < 1 || studentCount > 10) {
        cout << "Invalid. Please enter between 1 to 10: ";
        cin >> studentCount;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, students[i].name);
        cout << "Enter age: ";
        cin >> students[i].age;
        cout << "Enter CPA: ";
        cin >> students[i].cpa;

        insertSubjects(students[i]);
    }
}

int main() {
    Student students[10];
    int studentCount;

    insertStudents(students, studentCount);

    cout << "\n===== STUDENT LIST =====\n";
    for (int i = 0; i < studentCount; i++) {
        displayStudent(students[i]);
        cout << "-----------------------------\n";
    }

    return 0;
}