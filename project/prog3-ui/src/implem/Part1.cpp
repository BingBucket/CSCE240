#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part1.h"
using namespace std;

regex legal("^Legal [A-Z][a-z]{6,}");


void Part1::readLegal(string filename){
    int count = 0;
    string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (std::regex_match(line, std::regex(legal)))
            {
                count++;

            }
            if(count == 2)
                {
                    legalStatement += "\n"+ line;
                    while(getline(inputFile, line))
                    {

                        if (line == "" || line == " ")
                        {
                            count ++;
                            output += legalStatement;
                            return;
                        }
                        legalStatement += "\n" + line;
                        
                    }
                }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}