#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <Shape.h>

class Triangle : public Shape{
    public:
    int side1;
    int side2;
    int side3;

    double getPerimeter(int side1, int side2, int side3){
        return side1 + side2 + side3;
    }
    double getArea(int side1, int side2, int side3){
        return (side1 * side2) / 2;
    }

    std::string getErrorMessage(){
        return "";

    }
    };



#endif // Triangle