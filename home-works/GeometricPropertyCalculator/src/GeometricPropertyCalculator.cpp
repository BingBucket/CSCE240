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
int lines = 6;
struct Shape{
    string Name = "name";
    int dimension1 = 0;
    int dimension2 = 0;
    int dimension3 = 0;
};

struct Shape *shape = new Shape[6];

int countFileLine() {
    string line;
    int lines = 0;
	ifstream inputFile("input.txt");
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
    countFileLine();
    int i = 0;
	ifstream inputFile("input.txt");
	if (inputFile.is_open()) {
        stringstream ss(line);
		while (getline(inputFile, line)) {
            ss >> ShapeName >> dimension1 >> dimension2 >> dimension3;
            shape[i].Name = ShapeName.c_str();
            shape[i].dimension1 = dimension1;
            shape[i].dimension2 = dimension2;
            shape[i].dimension3 = dimension3;
            i+=1;
		}

		inputFile.close();
	} else {
		cout << "File could not be opened!" << endl;
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
    return output;
 }

 int main() {
    cout << "Reading file...\n";
    readFile();
    cout << "Would you like to calculate the area or perimeter of a shape?\n" << "Press 1 to calculate the area\nPress 2 to calculate the perimeter\n";
    char command = 0;
    cin >> command;
    if (command == '1') {
            ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < lines; i++) {
            calculateArea(shape[i].Name, shape[i].dimension1, shape[i].dimension2, shape[i].dimension3);
            outputFile << shape[i].Name << " " << " Area: " << output << endl;
            }
        outputFile.close();
        } 
        else {
            cout << "File could not be opened!" << endl;
        }
    }
    else if(command == '2') {
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < lines; i++) {
            calculatePerimeter(shape[i].Name, shape[i].dimension1, shape[i].dimension2, shape[i].dimension3);
            outputFile << shape[i].Name << " " << " Perimeter: " << output << endl;
            }
        outputFile.close();
    }
        else {
            cout << "File could not be opened!" << endl;
        }
    cout << "Done!\n";
    return 0;
}
 }