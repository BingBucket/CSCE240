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
    std::string partnum;
    std::string filename;

    Part();
    Part(std::string partnum);
    void readFile(std::string filename);

};

#endif //Part