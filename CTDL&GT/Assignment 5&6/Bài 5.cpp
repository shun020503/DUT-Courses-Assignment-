#include <bits/stdc++.h>
using namespace std;
string decimalToBinary(int decimalNumber) {
    stack<int> binaryStack;
    if (decimalNumber == 0) {
        return "0";
    }
    while (decimalNumber > 0) {
        int remain = decimalNumber % 2;
        binaryStack.push(remain);
        decimalNumber /= 2;
    }
    string binaryString = "";
    while (!binaryStack.empty()) {
        binaryString += to_string(binaryStack.top());
        binaryStack.pop();
    }
    return binaryString;
}
int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    string binaryString = decimalToBinary(decimalNumber);
    cout << "Binary representation: " << binaryString << endl;
    return 0;
}
