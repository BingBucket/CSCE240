#include "../header/Part.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

//regex paranum is used mainly for the ParamountGlobal text file, as it outlines page numbers in the following manner.
//All three regex will be used to check if the line is simply for a page number, so it can be skipped.
std::regex paramountnum("^[I-Z]+[I-Z]?-[0-9]+");
//regex tableofcontents and netflixnum are for the Netflix file, as the text file puts the page number in one line, and the string "Table of Contents" on the next line.
std::regex tableofcontents("Table of Contents");
std::regex netflixnum("^[0-9]+");

/*The below sections: legal, market risk, directors, and financial statements, are not directly written in the 
* corresponding items and sections. Instead, the corresponding item simply directs you to an entirely different
* part of the 10-k file. 
* To fix this, the regex below are used to find the specific references that the items point to.
*/
std::regex legal("^Legal [A-Z][a-z]{6,}");
std::regex marketrisk("^Market Risk");
std::regex directors("^(\\*\\		)?[A-Z][a-z]{1,}-?[a-zA-Z]*.+(	)(January|February).+202(3|4)$");
std::regex statement("CONSOLIDATED STATEMENTS OF OPERATIONS");

void Part::determineProcess(std::string process) {
    if(process == "part1"){
        finder= "PART I";
        ender= "PART II";
        enderalt = "PART II";
    }
    else if(process == "business"){
        finder = "Item 1.";
        ender = "Item 1A.";
        enderalt = "Item 1A.Risk Factors";
    }
    else if(process == "riskfactors"){
        finder = "Item 1A.";
        ender = "Item 1B.";
        enderalt = "Item 1B.Unresolved Staff Comments";
    }
    else if(process == "properties") {
        finder = "Item 2.";
        ender = "Item 3.";
        enderalt = "Item 3.Legal Proceedings";
    }
    else if(process == "legal") {
        finder = "Item 3.";
        ender = "Item 4.";
        enderalt = "Item 4.Mine Safety Disclosures";
    }
    else if (process == "part2"){
        finder = "PART II";
        ender = "PART III";
        enderalt = "PART III";
    }
    else if (process == "market"){
        finder = "Item 5.";
        ender = "Item 6.[Reserved]";
        enderalt = "Item 7.";
    }
    else if (process == "disclosure"){
        finder = "Item 7A.";
        ender = "Item 8.";
        enderalt = "Item 8.Financial Statements and Supplementary Data";

    }
    else if (process == "part3"){
        finder = "PART III";
        ender = "PART IV";
        enderalt = "PART IV";
    }
    if (process == "directors"){
        finder = "Item 10.";
        ender = "Item 11.Executive Compensation";
        enderalt = "Item 11.";
    }
    else if (process == "compensation"){
        finder = "Item 11.";
        ender = "Item 12.Security Ownership of Certain Beneficial Owners and Management and Related Stockholder Matters";
        enderalt = "Item 12.";
    }
    else if (process == "financialstatement"){
        finder = "Item 15.";
        ender = "Item 16.";
        enderalt = "Item 16. Form 10–K Summary";
    }
    else if (process == "part4"){
        finder = "PART IV";
        ender = "None.";
        enderalt = "None.";
    }
    else if (process == "partAll"){
        finder = "PART I";
        ender = "Item 16.";
        enderalt = "Item 16. Form 10-k Summary";
    }
}

void Part::readFile(std::string filename){
    std::string line;
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
        std::cout << "Unable to open file";
    }
    }

//Reads the legal statements from the file and adds it to the output string.
    void Part::readLegal(std::string filename){
    int count = 0;
    std::string line;
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
        std::cout << "Unable to open file";
    }
    }

//Reads the disclosure market risk information and adds it to the output string.
void Part::readDisclosure(std::string filename){
    std::string line;
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
        std::cout << "Unable to open file";
    }
}

//Reads the list of directors according to the directors regex and adds it to the output string.
void Part::readDirectors(std:: string filename){
    std::string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (std::regex_match(line, std::regex(directors)))
            {
                getline(inputFile, line);
                directorsList += "\n" + line;
            }
        }
        output += directorsList;
        inputFile.close();
    }
    else{
        std::cout << "Unable to open file";
    }
}

//Reads the financial statements and adds it to the output string.
void Part::readConsolidatedStatement(std::string filename){
    std::string line;
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
        std::cout << "Unable to open file";
    }
}

void Part::writeFile() {
    std::ofstream outputFile("../../txt/output.txt");
    if (outputFile.is_open()) {
        outputFile << output << std::endl;
        outputFile.close();

    }
    else std::cout << "File could not be opened!" << std::endl;
 }

