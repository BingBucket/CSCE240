#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

string ShapeName;
int dimension1;
int dimension2;
int dimension3;
double output;
int lines;
struct Shape{
    string Name;
    int dimension1;
    int dimension2;
    int dimension3;
};

Shape *shape = new Shape[lines];

int countFileLine() {
    string line;
    int lines = 0;
	ifstream inputFile("data/input.txt");
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
            lines+=1;
		}

		inputFile.close();
	} else {
		cout << "File could not be opened!";
    }
    return lines;

 }
void readFile() {
    string line;
    int countFileLine();
    int i = 0;
	ifstream inputFile("data/input.txt");
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
            stringstream ss(line);
            ss >> ShapeName >> dimension1 >> dimension2 >> dimension3;
            shape[i] = {ShapeName, dimension1, dimension2, dimension3};
            i+=1;
		}

		inputFile.close();
	} else {
		cout << "File could not be opened!";
    }

 }

 double calculateArea(string ShapeName, int dimension1, int dimension2, int dimension3) {

    if (ShapeName == "Triangle") {
        output = (dimension1 * dimension2) / 2;
    }
    else if (ShapeName == "Square") {
        output = dimension1 * dimension1;
    }
    else if (ShapeName == "Rectangle") {
        output = dimension1 * dimension2;
    }
    return output;
 }
 double calculatePerimeter(string ShapeName, int dimension1, int dimension2, int dimension3) {
    if (ShapeName == "Triangle") {
        output = dimension1 + dimension2 + dimension3;
    }
    else if (ShapeName == "Square") {
        output = dimension1 * 4;
    }
    else if (ShapeName == "Rectangle") {
        output = 2 * dimension1 + 2 * dimension2;
    }
 }

 int main() {
    cout << "Reading file...\n";
    readFile();
    cout << "Would you like to calculate the area or perimeter of a shape?\n" << "Press 1 to calculate the area\nPress 2 to calculate the perimeter\n";
    char command = 0;
    cin >> command;
    if (command == '1') {
            ofstream outputFile("data/output.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < lines; i++) {
            calculateArea(shape[i].Name, shape[i].dimension1, shape[i].dimension2, shape[i].dimension3);
            outputFile << shape[i].Name << " " << " Area: " << output << endl;
            }
        outputFile.close();
        } 
        else {
            cout << "File could not be opened!";
        }
    }
    else if(command == '2') {
        ofstream outputFile("data/output.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < lines; i++) {
            calculatePerimeter(shape[i].Name, shape[i].dimension1, shape[i].dimension2, shape[i].dimension3);
            outputFile << shape[i].Name << " " << " Perimeter: " << output << endl;
            }
        outputFile.close();
    }
        else {
            cout << "File could not be opened!";
        }
    cout << "Done!\n";
    return 0;
}
 }