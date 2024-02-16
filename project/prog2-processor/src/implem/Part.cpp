#include "../header/Part.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

//regex paranum is used mainly for the ParamountGlobal text file, as it outlines page numbers in the following manner.
//All three regex will be used to check if the line is simply for a page number, so it can be skipped.
regex paramountnum("^[I-Z]+[I-Z]?-[0-9]+");
//regex tableofcontents and netflixnum are for the Netflix file, as the text file puts the page number in one line, and the string "Table of Contents" on the next line.
regex tableofcontents("Table of Contents");
regex netflixnum("^[0-9]+");
std::string output;
std::string finder;
std::string ender;
std::string enderalt;

Part::Part(){

}

void Part::readFile(std::string filename){
    string line;
    int count = 0;
    bool skip = false;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (line.find(finder) != std::string::npos )
            {
                count++;

            }
            if(count == 2)
                {
                    while(getline(inputFile, line))
                    {
                        //skip boolean is turned to false every iteration in case the boolean is true from a past iteration.
                        skip = false;
                        //This if statement is to stop the output when it reaches the next section.
                        //Whenever it finds the line with the corresponding string, it will increment the count by 1.
                        if (line == ender || line == enderalt)
                        {
                            count ++;
                            return;
                        }
                        //Checks if the line matches any of the three outlined regex patterns. If it does, then it changes the boolean to true and skips the line.
                        if (regex_match(line, paramountnum) || regex_match(line, tableofcontents) || regex_match(line, netflixnum)){
                            skip = true;

                        }
                        if (!skip){
                            output += "\n" + line;
                        }
                    }
                }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
    }

void writeFile() {
    ofstream outputFile("../../txt/output.txt");
    if (outputFile.is_open()) {
        outputFile << output << endl;
        outputFile.close();

    }
    else cout << "File could not be opened!" << endl;
 }

