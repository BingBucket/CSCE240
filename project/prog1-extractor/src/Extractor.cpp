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
    lineCount = 0;
    wordCount = 0;
    charCount = 0;
    partCount = 0;
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

//Function that checks if there is a duplicate .txt file that already has information in the file. If so, then it outputs to the console to tell the user of a possible duplicate.
 void checkDupe(string fileName){
     ifstream inputFile("../txt/output.txt");
     if (inputFile.is_open()) {
         string line;
         while (getline(inputFile, line)) {
             if(line.find(fileName)!= string::npos){
                 cout << fileName << " is a duplicate! Please check output file to ensure there are no copies." << endl;
                 Dupe = true;
                 return;
             }
             else{
                 Dupe = false;
             }
         }
         inputFile.close();
     } else
         cout << "File could not be opened!" << endl;
 }

void writeFile(string fileName) {
    Dupe = false;
    checkDupe(fileName);
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
    //The previous ParamountGlobal 10k file, denoted now as "ParamountGl-10qOLD.txt", was the wrong file. The correct file has been uploaded, and the code has been updated to take in the correct file.
    cout << "Reading the ParamountGlobal 10k file..." << endl;
    readFile("ParamountGlobal-10k.txt");
    writeFile("ParamountGlobal-10k.txt");
    return 0;
 }
