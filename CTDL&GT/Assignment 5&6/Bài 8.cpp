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
    queue<char> charQueue;
    char currentChar;
    while (inputFile.get(currentChar)) {
        charQueue.push(currentChar);
    }
    while (!charQueue.empty()) {
        char dequeuedChar = charQueue.front();
        charQueue.pop();
        outputFile.put(toupper(dequeuedChar));
    }
    cout << "File conversion complete." << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}
