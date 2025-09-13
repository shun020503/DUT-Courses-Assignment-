#include <bits/stdc++.h>
using namespace std;

int removeEvenNumbers(stack<int>& inputStack) {
    stack<int> tempStack;
    int removedCount = 0;
    while (!inputStack.empty()) {
        int currentNum = inputStack.top();
        inputStack.pop();
        if (currentNum % 2 != 0) {
            tempStack.push(currentNum);
        } else {
            removedCount++;
        }
    }
    while (!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
    return removedCount;
}

int main() {
    stack<int> numbersStack;
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);
    numbersStack.push(4);
    numbersStack.push(5);
    int removedCount = removeEvenNumbers(numbersStack);
    cout << "Removed " << removedCount << " even numbers." << endl;
    cout << "Remaining numbers in the stack: ";
        while (!numbersStack.empty()) {
        cout << numbersStack.top() << " ";
        numbersStack.pop();
    }
    cout << endl;
    return 0;
}
