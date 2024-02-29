#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part4.h"
#include "Part.cpp"

using namespace std;
regex statement("CONSOLIDATED STATEMENTS OF OPERATIONS");
std::string financialStatements;

void Part4::readConsolidatedStatement(std::string filename){
    string line;
    bool skip = false;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (line == "CONSOLIDATED STATEMENTS OF OPERATIONS")
            {
                while(getline(inputFile, line))
                    {
                        skip = false;

                        if (line == "NOTES TO CONSOLIDATED FINANCIAL STATEMENTS")
                        {
                            output += financialStatements;
                            return;
                        }
                        if (std::regex_match(line, std::regex(paramountnum)) || std::regex_match(line, std::regex(tableofcontents)) || std::regex_match(line, std::regex(netflixnum))){
                            skip = true;

                        }
                        if (!skip){
                            financialStatements += "\n" + line;
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