#include <bits/stdc++.h>
using namespace std;

bool isValidUsername(const std::string& username) {
    if (username.length() > 15)  return false;
    for (char ch : username) 
    if (!isalnum(ch) && ch != '_')  return false;
    return true;
}

bool isValidPassword(const std::string& password) {
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    for (char ch : password)  
    if (isupper(ch))  hasUppercase = true;
    else if (islower(ch)) hasLowercase = true;
    else if (isdigit(ch)) hasDigit = true;
    else if (ispunct(ch)) hasSpecialChar = true;
    return hasUppercase && hasLowercase && hasDigit && hasSpecialChar;
}
int main() {
    unordered_map<string, string> table;
    table["alice"] = "password1";
    table["bob"] = "pass2";
    table["jane"]= "thisIsmyPas";
    while (true) {
        string enteredUsername, enteredPassword;
        cout << "Username: ";
        if (!(cin >> enteredUsername))  break;
        cout << "Password: ";
        if (!(cin >> enteredPassword))  break;
        auto it = table.find(enteredUsername);
        if (it != table.end() && it->second == enteredPassword) {
            cout << "Authentication successful" << endl;
        } else {
            cout << "Authentication failure" << endl;
        }
    }
    return 0;
}