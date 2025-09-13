#include <bits/stdc++.h>
using namespace std;

queue<int> getNegativeElements(const queue<int>& inputQueue) {
    queue<int> negativeQueue;
    queue<int> tempQueue = inputQueue;
    while (!tempQueue.empty()) {
        int currentElement = tempQueue.front();
        tempQueue.pop();
        if (currentElement < 0) {
            negativeQueue.push(currentElement);
        }
    }
    return negativeQueue;
}
int main() {
    queue<int> numbersQueue;
    numbersQueue.push(-2);
    numbersQueue.push(5);
    numbersQueue.push(-7);
    numbersQueue.push(10);
    numbersQueue.push(-3);
    queue<int> negativeQueue = getNegativeElements(numbersQueue);
    cout << "Original Queue: ";
    while (!numbersQueue.empty()) {
        cout << numbersQueue.front() << " ";
        numbersQueue.pop();
    }
    cout << "\nNegative Elements Queue: ";
    while (!negativeQueue.empty()) {
        cout << negativeQueue.front() << " ";
        negativeQueue.pop();
    }
    cout << endl;
    return 0;
}
