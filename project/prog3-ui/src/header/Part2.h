#ifndef PART2_H_
#define PART2_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Part.h"

class Part2 : public Part {
    public:
    std::string market;
    std:: string disclosures;

    Part2();
    void determineProcess(std::string process);
    void readDisclosure(std::string filename);
    

};
#endif // PART2_H_