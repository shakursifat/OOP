#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x;
    double y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double getx()
    {
        return x;
    }

    double gety()
    {
        return y;
    }

    void setCoordinates(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point getCoordinates()
    {
        return *this;
    }
    Point translate(double dx, double dy)
    {
        Point temp;
        temp.x = x + dx;
        temp.y = y + dy;
        return temp;
    }

    double cross(const Point &other)
    {
        return x * other.y - y * other.x;
    }

    double getDistance(const Point &other)
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    void display()
    {
        printf("(%lf,%lf)\n", x, y);
    }
};

class Polygon
{
    Point *vertices = NULL;
    int numVertices;

public:
    Polygon()
    {
        vertices = new Point[10];
        numVertices = 0;
    }
    Polygon(Point *vertices, int n)
    {
        this->vertices = new Point[n];
        numVertices = n;
        for (int i = 0; i < numVertices; i++)
        {
            this->vertices[i] = vertices[i];
        }
    }
    void addVertex(Point p)
    {
        vertices[numVertices] = p;
        numVertices++;
    }
    double getPerimeter()
    {
        double peri = 0;
        for (int i = 0; i < numVertices; i++)
        {
            peri += vertices[i].getDistance(vertices[(i + 1) % numVertices]);
        }
        return peri;
    }
    double getArea()
    {
        double area = 0;
        for (int i = 0; i < numVertices; i++)
        {
            area += (vertices[i].getx() * vertices[(i + 1) % numVertices].gety() -
                     vertices[i].gety() * vertices[(i + 1) % numVertices].getx());
        }
        return area / 2;
    }

    Polygon translate(double dx, double dy)
    {
        Point *temp = new Point[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
           temp[i] = vertices[i].translate(dx, dy);
        }
        return Polygon(temp, numVertices);
    }

    void display()
    {
        for (int i = 0; i < numVertices; i++)
        {
            vertices[i].display();
        }
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);Point vertices[] = {p1, p2, p3};
    Polygon triangle(vertices,3);
    Polygon translatedTriangle = triangle.translate(2, 1);
    cout << "Original Triangle:\n";
    triangle.display();
    cout << "\nTranslated Triangle:\n";
    translatedTriangle.display();
    Polygon square = triangle;
    square.addVertex(p4);
    cout << "\nSquare:\n";
    square.display();
    cout << triangle.getArea() << endl;
    cout << triangle.getPerimeter() << endl;
    cout << square.getArea() << endl;
    cout << square.getPerimeter() << endl;
    return 0;
}
