#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(const string& str) {
    stack<char> charStack;
    auto isAlphanumeric = [](char c) {
        return isalnum(static_cast<unsigned char>(c));
    };
    for (char c : str) {
        if (isAlphanumeric(c)) {
            charStack.push(tolower(c)); 
        }
    }
    for (char c : str) {
        if (isAlphanumeric(c)) {
            if (charStack.empty() || charStack.top() != tolower(c)) {
                return false; // Characters do not match, not a palindrome
            }
            charStack.pop();
        }
    }
    return charStack.empty(); 
}
int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);
    if (isPalindrome(inputString)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
