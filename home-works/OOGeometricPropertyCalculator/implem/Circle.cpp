
#include "Circle.h"

double Circle::getArea(int radius){
    if(radius <=0){
        getErrorMessage();
    }
    return 3.14 * radius * radius;

}

double Circle::getPerimeter(int radius){
    if(radius <=0){
        getErrorMessage();
    }
    return 2* radius *3.14;
}

string Circle::getErrorMessage(){
    return "There is not enough information for the circle to calculate.";
}