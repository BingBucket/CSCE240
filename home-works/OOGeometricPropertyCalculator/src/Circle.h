#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <string>
#include "Shape.h"

class Circle: public Shape{
public:
    std::string name;
    int radius;
    double getArea(int radius);
    double getPerimeter(int radius);
    std::string getErrorMessage();
};

#endif //Circle