#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(const string& postfix) {
    stack<string> operandStack;
    for (char c : postfix) {
        if (!isOperator(c)) {
            operandStack.push(string(1, c));
        } else {
            string operand2 = operandStack.top();
            operandStack.pop();
            string operand1 = operandStack.top();
            operandStack.pop();
            string infixExpression = "(" + operand1 + c + operand2 + ")";
            operandStack.push(infixExpression);
        }
    }
    return operandStack.top();
}

int main() {
    string postfixExpression; int c=0, p=0;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;
    for (auto i : postfixExpression)
        if (isOperator(i)) p++; else c++;
    if (p==c-1)
    {
        string infixExpression = postfixToInfix(postfixExpression);
        cout << "Infix expression: " << infixExpression << endl;
    }
    else cout << "Invalid Expression!" << endl;
    return 0;
}
