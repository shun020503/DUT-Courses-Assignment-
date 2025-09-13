#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    int sqrtNum = static_cast<int>(sqrt(num));
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true; 
}
stack<int> filterPrimes(const stack<int>& inputStack, int& primeCount) {
    stack<int> resultStack;
    primeCount = 0;
    stack<int> tempStack = inputStack; 
    while (!tempStack.empty()) {
        int currentNum = tempStack.top();
        tempStack.pop();
        if (isPrime(currentNum)) {
            resultStack.push(currentNum);
            primeCount++;
        }
    }
    return resultStack;
}
int main() {
    stack<int> inputStack;
    inputStack.push(2);
    inputStack.push(5);
    inputStack.push(8);
    inputStack.push(7);
    inputStack.push(11);
    int primeCount;
    stack<int> resultStack = filterPrimes(inputStack, primeCount);
    cout << "Original Stack: ";
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << "\nPrime Numbers Stack: ";
    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
    cout << "\nTotal Number of Prime Numbers: " << primeCount << endl;
    return 0;
}
