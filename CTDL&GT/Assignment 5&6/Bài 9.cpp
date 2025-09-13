#include <bits/stdc++.h>

using namespace std;

void moveStackToQueueIterative(stack<int>& inputStack, queue<int>& outputQueue) {
    while (!inputStack.empty()) {
        outputQueue.push(inputStack.top());
        inputStack.pop();
    }
}

void moveStackToQueueRecursive(stack<int>& inputStack, queue<int>& outputQueue) {
    if (inputStack.empty()) {
        return;
    }
    int topElement = inputStack.top();
    inputStack.pop();
    moveStackToQueueRecursive(inputStack, outputQueue);
    outputQueue.push(topElement);
}

int main() {
    stack<int> numbersStack;
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);
    numbersStack.push(4);
    numbersStack.push(5);
    queue<int> movedQueueIterative;
    queue<int> movedQueueRecursive;
    moveStackToQueueIterative(numbersStack, movedQueueIterative);
    cout << "Iterative Function - Moved Elements to Queue: ";
    while (!movedQueueIterative.empty()) {
        cout << movedQueueIterative.front() << " ";
        movedQueueIterative.pop();
    }
    cout << "\nOriginal Stack (unchanged): ";
    while (!numbersStack.empty()) {
        cout << numbersStack.top() << " ";
        numbersStack.pop();
    }
    cout << endl;
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);
    numbersStack.push(4);
    numbersStack.push(5);
    moveStackToQueueRecursive(numbersStack, movedQueueRecursive);
    cout << "\nRecursive Function - Moved Elements to Queue: ";
    while (!movedQueueRecursive.empty()) {
        cout << movedQueueRecursive.front() << " ";
        movedQueueRecursive.pop();
    }
    cout << "\nOriginal Stack (unchanged): ";
    while (!numbersStack.empty()) {
        cout << numbersStack.top() << " ";
        numbersStack.pop();
    }
    cout << endl;
    return 0;
}
