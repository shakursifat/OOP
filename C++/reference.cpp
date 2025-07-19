#include <iostream>

using namespace std;

class Coord{
    int x, y;
public:
    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Coord& operator++() {
        ++x;
        ++y;
        return *this;
    }

    Coord& operator++(int x) {
        ++x;
        ++y;
        return *this;
    }

    void show() {
        cout << x << " " << y << endl;
    }

    ~Coord() {
        cout << "destructing " << x  << endl;
    }
};

int main() {
    Coord p(10, 20);

    p.show();

    ++p;

    p.show();

    p++;

    p.show();

}