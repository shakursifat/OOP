#include<iostream>
using namespace std;

class Figure {
protected:
    double dim1, dim2;
public:
    Figure(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    virtual double area() = 0;
        
};

class Rectangle: public Figure {
public:
    Rectangle(double d1, double d2): Figure(d1, d2) {}

    double area() {
        return dim1*dim2;
    }
};

class Triangle : public Figure {
public:
    Triangle(double d1, double d2): Figure(d1, d2) {}

    double area() {
        return dim1 * dim2 / 2;
    }
};

int main() {
    Figure *p;

    Rectangle r(10, 7);
    Triangle t(10, 5);

    p = &r;
    cout << "Rectangle Area: " << p->area() << endl;

    p = &t;

    cout << "Triangle Area: " << p->area() << endl;

}