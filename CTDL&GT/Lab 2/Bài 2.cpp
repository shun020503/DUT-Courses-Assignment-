#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}

int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; 
    }
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    unordered_map<char, int> precedence;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main() {
    string infix1 = "A+B*(C^D-E)^(F+G*H)-I";
    string postfix1 = infixToPostfix(infix1);
    cout << "Infix: " << infix1 << endl;
    cout << "Postfix: " << postfix1 << endl;
    string infix2 = "A*(B+C)/D";
    string postfix2 = infixToPostfix(infix2);
    cout << "Infix: " << infix2 << endl;
    cout << "Postfix: " << postfix2 << endl;
    return 0;
}
