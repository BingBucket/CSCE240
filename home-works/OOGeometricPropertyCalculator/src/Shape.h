

#ifndef SHAPE_H_
#define SHAPE_H_
#include <String>

using namespace std;

class Shape {
    public:
    string shapeName;
    double area;
    double perimeter;
    int dimension1, dimension2, dimension3;
    Shape();
    Shape(string shapeName, int dimension1, int dimension2, int dimension3);

    double getArea();
    double getPerimeter();
    string getErrorMessage();


};

#endif // Shape.h