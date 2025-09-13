#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}

int evaluatePrefix(string expression) {
    stack<int> Stack;
    for (int i = expression.size() - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            Stack.push(expression[i] - '0');
        }
        else if (isOperator(expression[i])) {
            int op1 = Stack.top();
            Stack.pop();
            int op2 = Stack.top();
            Stack.pop();

            switch (expression[i]) {
                case '+':
                    Stack.push(op1 + op2);
                    break;
                case '-':
                    Stack.push(op1 - op2);
                    break;
                case '*':
                    Stack.push(op1 * op2);
                    break;
                case '/':
                    Stack.push(op1 / op2);
                    break;
            }
        }
    }
    return Stack.top();
}
int main() {
    string expression;
    int p=0, c=0;
    cout << "Enter the expression: ";
    getline(cin,expression);
    for (auto i : expression)
        if (isOperator(i)) p++; else c++;
    if (p==c-1) cout << evaluatePrefix(expression) << endl;
    else cout << "Invalid Expression";
    return 0;
}