#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Triangle.h>
#include <Shape.h>
#include <Rectangle.h>
#include <Circle.h>

using namespace std;
int dim1;
int dim2;
int dim3;
string Name;
int lines;
Triangle t;
Rectangle r;
Circle c;
Shape shapeArray[6];
void readFile() {
    string line;
	ifstream inputFile("../data/input.txt");
	if (inputFile.is_open()) {
        lines = 0;
		while (getline(inputFile, line)) {
            stringstream ss(line);
            ss << Name << dim1 << dim2 << dim3;
            shapeArray[lines].shapeName = Name;
            shapeArray[lines].dimension1 = dim1;
            shapeArray[lines].dimension2 = dim2;
            shapeArray[lines].dimension3 = dim3;
            lines++;
		}

		inputFile.close();
	} else
		cout << "File could not be opened!" << endl;

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
                if(shapeArray[i].shapeName == "TRIANGLE") {
                    outputFile << shapeArray[i].shapeName << t.getArea(shapeArray[i].dimension1, shapeArray[i].dimension2, shapeArray[i].dimension3) << endl;
                }
                else if(shapeArray[i].shapeName == "RECTANGLE") {
                    outputFile << shapeArray[i].shapeName << r.getArea(shapeArray[i].dimension1, shapeArray[i].dimension2) << endl;
                }
                else if(shapeArray[i].shapeName == "CIRCLE") {
                    outputFile << shapeArray[i].shapeName << c.getArea(shapeArray[i].dimension1) << endl;
                }
                else {
                    outputFile << "Error: Not a valid shape" << endl;
                }
            }


        outputFile.close();
        } 
        else {
            cout << "File could not be opened!" << endl;
        }
    }
    
    else if(command == '2') {
        ofstream outputFile("../data/output.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < lines; i++) {
            if(shapeArray[i].shapeName == "TRIANGLE") {
                outputFile << shapeArray[i].shapeName << t.getPerimeter(shapeArray[i].dimension1, shapeArray[i].dimension2, shapeArray[i].dimension3) << endl;
            }
            else if(shapeArray[i].shapeName == "RECTANGLE") {
                outputFile << shapeArray[i].shapeName << r.getPerimeter(shapeArray[i].dimension1, shapeArray[i].dimension2) << endl;
            }
            else if(shapeArray[i].shapeName == "CIRCLE") {
                outputFile << shapeArray[i].shapeName << c.getPerimeter(shapeArray[i].dimension1) << endl;
            }
            else {
                outputFile << "Error: Not a valid shape" << endl;
            }
            }
        outputFile.close();
    }
        else {
            cout << "File could not be opened!" << endl;
        }
    }
    else {
        cout << "Please enter 1 or 2" << endl;
    }
    cout << "Done!\n";
    return 0;
}