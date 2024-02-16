#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"

class Triangle : public Shape{
    public:
    int side1;
    int side2;
    int side3;

    double getPerimeter(int side1, int side2, int side3);
    double getArea(int side1, int side2, int side3);

    std::string getErrorMessage();
    };



#endif // Triangle