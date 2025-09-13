#include <bits/stdc++.h>
using namespace std;
int main() {
    string inputFileName = "input.txt";    
    string outputFileName = "output.txt"; 
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    stack<char> charStack;
    char currentChar;
    while (inputFile.get(currentChar)) {
        charStack.push(currentChar);
    }
    while (!charStack.empty()) {
        outputFile.put(charStack.top());
        charStack.pop();
    }
    cout << "File reversal complete." << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}
