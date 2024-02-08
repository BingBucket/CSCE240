#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <Shape.h>

class Circle: public Shape{
public:
    std::string name;
    int radius;
    double getArea(int radius){
        return 3.14*radius*radius;
    }
    double getPerimeter(int radius){
        return 2*3.14*radius;
    }
    std::string getErrorMessage(){
        return "";
    }
};

#endif //Circle