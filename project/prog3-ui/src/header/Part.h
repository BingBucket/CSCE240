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
std::string filename;
std::string process;

    Part();
    void readFile(std::string filename);
    void writeFile();
    void determineProcess(std:: string process);


};

#endif //Part