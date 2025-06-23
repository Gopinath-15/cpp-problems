#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int numSubjects;
    double* marks;
    double average;
    char letterGrade;

public:
    Student() {
        numSubjects = 0;
        marks = nullptr;
        average = 0.0;
        letterGrade = ' ';
    }

    void inputDetails() {
        cout << "Enter student name: ";
        cin.ignore(1, '\n'); // Clear buffer
        getline(cin, name);
        cout << "Enter number of subjects: ";
        cin >> numSubjects;

        while (numSubjects <= 0) {
            cout << "Invalid number! Enter a positive number: ";
            cin >> numSubjects;
        }

        marks = new double[numSubjects];
        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter marks for subject " << i + 1 << " (0-100): ";
            cin >> marks[i];
            while (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid marks! Enter between 0 and 100: ";
                cin >> marks[i];
            }
        }
    }

    void calculateAverage() {
        double sum = 0;
        for (int i = 0; i < numSubjects; i++) {
            sum += marks[i];
        }
        average = sum / numSubjects;
    }

    void assignLetterGrade() {
        if (average >= 90) letterGrade = 'A';
        else if (average >= 80) letterGrade = 'B';
        else if (average >= 70) letterGrade = 'C';
        else if (average >= 60) letterGrade = 'D';
        else letterGrade = 'F'; // Average < 50 is included in F
    }

    void displayResults() {
        cout << "\nStudent Report\n";
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < numSubjects; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage: " << average << endl;
        cout << "Letter Grade: " << letterGrade;
        if (letterGrade == 'F') cout << " (Fail)";
        else cout << " (Pass)";
        cout << endl;
    }

    ~Student() {
        delete[] marks;
    }
};

int main() {
    Student student;
    student.inputDetails();
    student.calculateAverage();
    student.assignLetterGrade();
    student.displayResults();
    return 0;
}
