#include <bits/stdc++.h>
using namespace std;
class MathStack {
private:
    stack<int> st;

public:
    void push(int value) {
        st.push(value);
    }
    int pop() {
        if (!st.empty()) {
            int top = st.top();
            st.pop();
            return top;
        } else {
            throw out_of_range("Stack is empty");
        }
    }
    bool isEmpty() const {
        return st.empty();
    }
    void add() {
        if (st.size() >= 2) {
            int secondOperand = pop();
            int firstOperand = pop();
            int result = firstOperand + secondOperand;
            push(result);
        } else {
            cout << "Not enough operands for addition" << endl;
        }
    }
    void sub() {
        if (st.size() >= 2) {
            int secondOperand = pop();
            int firstOperand = pop();
            int result = firstOperand - secondOperand;
            push(result);
        } else {
            cout << "Not enough operands for subtraction" << endl;
        }
    }

    void mult() {
        if (st.size() >= 2) {
            int secondOperand = pop();
            int firstOperand = pop();
            int result = firstOperand * secondOperand;
            push(result);
        } else {
            cout << "Not enough operands for multiplication" << endl;
        }
    }
    void div() {
        if (st.size() >= 2) {
            int secondOperand = pop();
            int firstOperand = pop();
            if (secondOperand != 0) {
                int result = firstOperand / secondOperand;
                push(result);
            } else {
                cout << "Error: Division by zero" << endl;
            }
        } else {
            cout << "Not enough operands for division" << endl;
        }
    }
    void addAll() {
        int result = 0;
        while (!st.empty()) {
            result += pop();
        }
        push(result);
    }
    void multAll() {
        int result = 1;
        while (!st.empty()) {
            result *= pop();
        }
        push(result);
    }
};

int main() {
    MathStack mathStack;
    mathStack.push(5);
    mathStack.push(3);
    mathStack.push(8);
    mathStack.add();
    cout << "After add: " << mathStack.pop() << endl;
    mathStack.sub();
    cout << "After sub: " << mathStack.pop() << endl;
    mathStack.mult();
    cout << "After mult: " << mathStack.pop() << endl;
    mathStack.div();
    cout << "After div: " << mathStack.pop() << endl;
    mathStack.push(2);
    mathStack.push(4);
    mathStack.push(6);
    mathStack.addAll();
    cout << "After addAll: " << mathStack.pop() << endl;
    mathStack.multAll();
    cout << "After multAll: " << mathStack.pop() << endl;
    return 0;
}
