
#include "Triangle.h"
#include <cmath>

double Triangle::getArea(int side1, int side2, int side3){
    if(side1 <=0 || side2 <=0 || side3 <=0)
    {
        getErrorMessage();
    }
    //Area of a triangle formula using code from https://www.studymite.com/cpp/examples/program-to-find-area-of-a-triangle-cpp
    double s =(side1 + side2 + side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));

}

double Triangle::getPerimeter(int side1, int side2, int side3){
    if(side1 <=0 || side2 <=0 || side3 <=0){
        getErrorMessage();
    }
    return side1 + side2 + side3;
}

string Triangle::getErrorMessage(){
    return "There is not enough information to calculate the following for the triangle";
}