#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part3.h"
#include "Part.cpp"

using namespace std;
regex directors("^(\\*\\		)?[A-Z][a-z]{1,}-?[a-zA-Z]*.+(	)(January|February).+202(3|4)$");
std::string directorsList;

void readDirectors(std:: string filename){
    std::string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (regex_match(line, directors))
            {
                getline(inputFile, line);
                directorsList += "\n" + line;
            }
        }
        output += directorsList;
        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}
