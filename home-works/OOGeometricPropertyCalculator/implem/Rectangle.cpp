
#include "Rectangle.h"

double Rectangle::getArea(int width, int height){
    if(width <= 0 || height <= 0)
    {
        getErrorMessage();
    }
    return width * height;

}

double Rectangle::getPerimeter(int width, int height){
    if(width <= 0 || height <= 0){
        getErrorMessage();
    }
    return 2 * width + 2*height;
}

string Rectangle::getErrorMessage(){
    return "There is not enough information to calculate the following for the rectangle";
}