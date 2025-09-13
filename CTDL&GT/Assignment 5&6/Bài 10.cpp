#include <bits/stdc++.h>
using namespace std;

queue<string> copyElementsWithSubarray(const queue<string>& inputQueue, const string& subarray) {
    queue<string> resultQueue;
    queue<string> tempQueue = inputQueue; 
    while (!tempQueue.empty()) {
        string currentElement = tempQueue.front();
        tempQueue.pop();
        if (currentElement.find(subarray) != string::npos) {
            resultQueue.push(currentElement);
        }
    }
    return resultQueue;
}
int main() {
    queue<string> elementsQueue;
    elementsQueue.push("12abc6");
    elementsQueue.push("ahgd67");
    elementsQueue.push("qtgab0");
    elementsQueue.push("ghab45");
    string subarray = "ab";
    queue<string> resultQueue = copyElementsWithSubarray(elementsQueue, subarray);
    cout << "Original Queue: ";
    while (!elementsQueue.empty()) {
        cout << elementsQueue.front() << " ";
        elementsQueue.pop();
    }
    cout << "\nNew Queue with Subarray \"" << subarray << "\": ";
    while (!resultQueue.empty()) {
        cout << resultQueue.front() << " ";
        resultQueue.pop();
    }
    cout << endl;
    return 0;
}
