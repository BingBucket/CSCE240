#ifndef PART3_H_
#define PART3_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Part.h"

class Part3 : public Part {
    public:
    std::string directors;
    std:: string compensation;

    Part3();
    void determineProcess(std::string process);
    void readDirectors(std::string filename);
    

};
#endif // PART3_H_