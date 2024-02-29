#ifndef PART4_H_
#define PART4_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Part.h"

class Part4 : public Part {
    public:
    std::string financialStatements;

    Part4();
    Part4(std::string financialStatements);
    ~Part4();

    void readConsolidatedStatement(string filename);
    

};
#endif // PART4_H_