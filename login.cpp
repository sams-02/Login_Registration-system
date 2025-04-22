#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Store user credentials in memory
map<string, string> credentials;

// Load credentials from file
void loadCredentials() {
    credentials.clear();
    ifstream fin("users.txt");
    string username, password;
    while (fin >> username >> password) {
        credentials[username] = password;
    }
    fin.close();
}

// Save credentials to file
void saveCredentials() {
    ofstream fout("users.txt");
    for (const auto& entry : credentials) {
        fout << entry.first << " " << entry.second << endl;
    }
    fout.close();
}

// Register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    loadCredentials();
    if (credentials.count(username)) {
        cout << "Username already exists. Try another one.\n";
        return;
    }
    cout << "Enter password: ";
    cin >> password;
    credentials[username] = password;
    saveCredentials();
    cout << "Registration successful!\n";
}

// Login an existing user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    loadCredentials();
    if (credentials.count(username) && credentials[username] == password) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

// Reset password for a user
void resetPassword() {
    string username, newPassword;
    cout << "Enter username: ";
    cin >> username;
    loadCredentials();
    if (!credentials.count(username)) {
        cout << "Username does not exist.\n";
        return;
    }
    cout << "Enter new password: ";
    cin >> newPassword;
    credentials[username] = newPassword;
    saveCredentials();
    cout << "Password reset successful!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n==== User Login System ====\n";
        cout << "1. Register\n2. Login\n3. Reset Password\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}