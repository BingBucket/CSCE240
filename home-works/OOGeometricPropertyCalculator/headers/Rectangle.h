#ifndef RECTANGLE_H

#define RECTANGLE_H

#include <string>
#include <Shape.h>

class Rectangle: public Shape{
    public:
    int width;
    int height;
    double getPerimeter(int width, int height){
        return 2*(width, height);
    }
    double getArea(int width, int height){
        return width * height;
    }
    std::string getErrorMessage(){
        return "";
    }
};

#endif // Rectangle