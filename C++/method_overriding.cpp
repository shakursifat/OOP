#include<iostream>
using namespace std;

class Figure {
    protected: double dim1, dim2;
public:
    Figure(double a, double b) {
        dim1 = a;
        dim2 = b;
    }

    virtual double area() = 0;
    virtual void show() {
        cout << "abstract";
    }
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b) : Figure(a, b) {};
    
    double area() override{
        return dim1*dim2;
    }

    void show() override{
        cout << "Rectangle Area: " << area();
    }
};

class Triangle : public Figure {
public:
    Triangle(double a, double b) : Figure(a, b) {};
    double area() override{
        return 0.5*dim1*dim2;
    }
    void show() override{
        cout << "\nTriangle area: " << area();
    }
};

int main() {
    Rectangle r(4,5);
    Triangle t(4, 5);
    Figure *figref;

    figref = &r;
    figref->show();
    figref = &t;
    figref->show();
    

}