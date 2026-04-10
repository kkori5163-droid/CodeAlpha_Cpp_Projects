#include <iostream>
using namespace std;

int gradeToPoint(char grade) {
    switch(grade) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'F': return 0;
        default: return 0;
    }
}

int main() {
    int n, credit, totalCredits = 0;
    char grade;
    float totalPoints = 0;

    cout << "Enter number of subjects: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "\nSubject " << i << endl;
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credit;

        totalPoints += gradeToPoint(grade) * credit;
        totalCredits += credit;
    }

    float cgpa = totalPoints / totalCredits;

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nCGPA: " << cgpa << endl;

    return 0;
}