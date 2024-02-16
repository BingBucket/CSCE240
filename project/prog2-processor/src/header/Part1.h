#ifndef PART1_H_
#define PART1_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Part.h"

class Part1 : public Part {
    public:
    std::string part1;
    std::string business;
    std::string riskFactors;
    std::string properties;
    std::string legal;

    Part1();
    void readFile(std::string fileName){

    }

    void readProperties(std::string fileName){
    }
    void readLegal(std::string fileName){
    }

};
#endif // PART1_H_