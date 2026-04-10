#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string user, pass;
    cin.ignore();
    cout << "Enter username: ";
    getline(cin, user);
    cout << "Enter password: ";
    getline(cin, pass);

    ofstream file("users.txt", ios::app);
    file << user << ":" << pass << endl;
    file.close();

    cout << "Registration Successful!" << endl;
}

void loginUser() {
    string user, pass, line;
    cin.ignore();
    cout << "Enter username: ";
    getline(cin, user);
    cout << "Enter password: ";
    getline(cin, pass);

    ifstream file("users.txt");
    string credentials = user + ":" + pass;
    bool isValid = false;

    while (getline(file, line)) {
        if (line == credentials) {
            isValid = true;
            break;
        }
    }
    file.close();

    if (isValid) {
        cout << "Login Successful!" << endl;
    } else {
        cout << "Login Failed! Incorrect username or password." << endl;
    }
}

int main() {
    int choice;
    
    cout << "--- User Management System ---" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid Option!" << endl;
    }

    return 0;
}