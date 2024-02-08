
#include "Circle.h"

double Circle::getArea(int radius){
    //Prints out the error message if the radius is 0 or negative.
    if(radius <=0){
        getErrorMessage();
    }
    //Returns the area of the circle.
    return 3.14 * radius * radius;

}

double Circle::getPerimeter(int radius){
    //Prints out the error message if the radius is 0 or negative.
    if(radius <=0){
        getErrorMessage();
    }
    //Returns the perimeter of the circle.
    return 2* radius *3.14;
}

string Circle::getErrorMessage(){
    return "There is not enough information for the circle to calculate.";
}