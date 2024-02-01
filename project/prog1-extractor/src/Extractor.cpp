#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int lineCount = 0;
int wordCount = 0;
int charCount = 0;
int partCount = 0;
string partNumber = "";
bool Dupe = false;

//The 10k files utilize roman numerals to denote parts. This function will translate a number to a string of the corresponding roman numeral, up to 9.
void romanNumeralCounter(int num){
    switch (num) {
        case 0:
            break;
        case 1:
            partNumber = "I";
            break;
        case 2:
            partNumber = "II";
            break;
        case 3:
            partNumber = "III";
            break;
        case 4:
            partNumber = "IV";
            break;
        case 5:
            partNumber = "V";
            break;
        case 6:
            partNumber = "VI";
            break;
        case 7:
            partNumber = "VII";
            break;
        case 8:
            partNumber = "VIII";
            break;
        case 9:
            partNumber = "IX";
            break;

    }

}
void readFile(string text) {
    string line;
    //This integer is used to find the individual parts of the 10k file.
    int partNum = 1;
	ifstream inputFile("../txt/" + text);
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
            //while looping through every line, the lineCount is incremented by 1.
            lineCount++;
            //Checks the length of the line and adds it to the charCount.
            charCount += line.length();

            romanNumeralCounter(partNum);

            //If it finds a string that matches the pattern of PART plus a roman numeral, then it increments the partCount by 1 and searches for the next sequential roman numeral.
            if(line.find("PART " + partNumber) != string::npos){
                partCount++;
                partNum++;
            }

            //Using stringstream word counter from w3resources:
            //https://www.w3resource.com/cpp-exercises/file-handling/cpp-file-handling-exercise-4.php
            stringstream ss(line);
            string word;
            //while loop that reads through a line and counts the number of words, incrementing the wordCount variable for each word.
            while(ss >> word){
                wordCount++;
            }
		}

		inputFile.close();
	} else
		cout << "File could not be opened!" << endl;

 }

//Function that checks if there is a duplicate .txt file that already has information in the file. If so, then it exits the function.
 void checkDupe(string fileName){
     ifstream inputFile("../txt/output.txt");
     if (inputFile.is_open()) {
         string line;
         while (getline(inputFile, line)) {
             if(line.find(fileName)!= string::npos){
                 cout << fileName << " is a duplicate!" << endl;
                 bool Dupe = true;
             }
             else{
                 bool Dupe = false;
             }
         }
         inputFile.close();
     } else
         cout << "File could not be opened!" << endl;
 }

void writeFile(string fileName) {
    checkDupe(fileName);
    //Checks to make sure that there is no duplicates to the file before appending the contents of the file to the output file.
    if(Dupe = true){
        return;
    }
    ofstream outputFile("../txt/output.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << fileName << " Information" << endl;
        outputFile << "Line Count: " << lineCount << endl;
        outputFile << "Word Count: " << wordCount << endl;
        outputFile << "Char Count: " << charCount << endl;
        outputFile << "Parts in the file: " << partCount << "\n" << endl;
        outputFile.close();

    }
    else cout << "File could not be opened!" << endl;
 }
 int main(int argc, char *argv[]) {
    cout << "Reading the Netflix 10k file..." << endl;
    readFile("Netflix-10k.txt");
    writeFile("Netflix-10k.txt");
    cout << "Reading the ParamountGl 10k file..." << endl;
    readFile("ParamountGl-10k.txt");
    writeFile("ParamountGl-10k.txt");
    return 0;


 }