#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string operation;
int num1;
int num2;
int result;
 void readFile() {
    string line;
	ifstream inputFile("input.txt");
	if (inputFile.is_open()) {
        int line_count = 1;

		while (getline(inputFile, line)) {
            if (line_count == 1) {
                operation = line;
            }
            else if (line_count == 2) {
                num1 = stoi(line);
            }
            else if (line_count == 3) {
                num2 = stoi(line);
            }
            line_count++;
		}

		inputFile.close();
	} else
		cout << "File could not be opened!";

 }

 void writeFile() {

    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "The result of " << operation << " on " << num1 << " and " << num2 << " is below: \n";
        outputFile << result;
        outputFile.close();

    }
    else cout << "File could not be opened!";
 }

 int calculate() {

    if (operation == "add"){
        result = num1 + num2;
    }
    else if (operation == "subtract"){
        result = num1 - num2;
    }
    else if (operation == "multiply"){
        result = num1 * num2;
    }
    else if (operation == "divide"){
        if (num2 == 0) {
            cout << "Cannot divide by 0!\n";
        }
        else {
            result = num1 / num2;
        }
    }
    return result;
 }

 int main() {
    cout << "Reading file...\n";
    readFile();
    cout << "Calculating...\n";
    calculate();
    cout << "Writing results...\n";
    writeFile();
    cout << "Done!\n";
    return 0;
}