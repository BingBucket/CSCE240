#ifndef RECTANGLE_H

#define RECTANGLE_H

#include <string>
#include "Shape.h"

class Rectangle: public Shape{
    public:
    int width;
    int height;
    double getPerimeter(int width, int height);
    double getArea(int width, int height);
    std::string getErrorMessage();
};

#endif // Rectangle