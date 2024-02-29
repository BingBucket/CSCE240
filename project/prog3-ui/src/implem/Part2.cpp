#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part2.h"

using namespace std;
std:: string disclosureStatement;
regex marketrisk("^Market Risk");

void Part2::readDisclosure(std::string filename){
    string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (std::regex_match(line, std::regex(marketrisk)))
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