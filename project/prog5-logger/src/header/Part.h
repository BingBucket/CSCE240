#ifndef PART_H_
#define PART_H_

#include <iostream>
#include <string>

class Part{
public:
std::string output;
std::string finder;
std::string ender;
std::string enderalt;

std:: string legalStatement;

std:: string disclosureStatement;

std::string directorsList;

std::string financialStatements;
    void readFile(std::string filename);
    void writeFile();
    void determineProcess(std::string process);

    void readLegal(std:: string filename);
    void readDisclosure(std::string filename);
    void readDirectors(std::string filename);
    void readConsolidatedStatement(std::string filename);


};

#endif //Part