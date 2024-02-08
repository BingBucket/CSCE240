
#include "Rectangle.h"

double Rectangle::getArea(int width, int height){
    //Prints out the error message if the width or height is less than or equal to 0.
    if(width <= 0 || height <= 0)
    {
        getErrorMessage();
    }
    //Returns the area of the rectangle.
    return width * height;

}

double Rectangle::getPerimeter(int width, int height){
    //Prints out the error message if the width or height is less than or equal to 0.
    if(width <= 0 || height <= 0){
        getErrorMessage();
    }
    //Returns the perimeter of the rectangle.
    return 2 * width + 2*height;
}

string Rectangle::getErrorMessage(){
    return "There is not enough information to calculate the following for the rectangle";
}