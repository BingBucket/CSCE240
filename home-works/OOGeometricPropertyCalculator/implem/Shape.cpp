
#include "Shape.h"

Shape::Shape(){
    
}
Shape::Shape(string shapeName, int dimension1, int dimension2, int dimension3){
    this->shapeName = shapeName;
    this->dimension1 = dimension1;
    this->dimension2 = dimension2;
    this->dimension3 = dimension3;
}

double Shape::getArea(){
    return area;
}

double Shape::getPerimeter(){
    return perimeter;
}

string Shape::getErrorMessage(){
    return "";
}