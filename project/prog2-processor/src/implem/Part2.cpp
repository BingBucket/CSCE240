#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part2.h"
#include "Part.cpp"

using namespace std;
std:: string process;
std:: string disclosureStatement;
regex marketrisk("^Market Risk");

void readDisclosure(std::string filename){
    string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (regex_match(line, marketrisk))
            {
                disclosureStatement += "\n" + line;
                while(getline(inputFile, line))
                    {

                        if (line == "" || line == " ")
                        {
                            output += disclosureStatement;
                            return;
                        }
                        disclosureStatement += "\n" + line;
                        
                    }
            }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}