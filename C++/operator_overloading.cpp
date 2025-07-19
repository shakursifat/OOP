#include<iostream>
using namespace std;

class Coord {
    int x, y;
public: 
    Coord(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    void getxy(int &i, int&j) {
        i = x;
        j = y;
    }

    Coord operator + (Coord ob);
    Coord operator + (int i);
    Coord operator ++(int);
    Coord operator ++();
    Coord operator *(Coord ob);
    Coord operator = (Coord ob);

    friend bool operator == (int x, Coord ob);
    friend Coord operator + (int x, Coord ob);
};

Coord Coord::operator + (Coord ob) {
    Coord temp;
    temp.x = x + ob.x;
    temp.y = y + ob.y;
    return temp;
}

Coord Coord::operator + (int i) {
    Coord temp;
    temp.x = x + i;
    temp.y = y + i;
    return temp;
}

Coord Coord:: operator ++(int notused) {
    Coord temp;
    temp.x = x++;
    temp.y = y++;
    return temp;
}

Coord Coord:: operator ++() {
    ++x;
    ++y;
    return *this;
}

Coord Coord:: operator *(Coord ob) {
    Coord temp;
    temp.x = x * ob.x;
    temp.y = y * ob.y;
    return temp;
}

bool operator ==(int x, Coord ob) {
    return (x == ob.x && x == ob.y);
}

Coord operator +(int x, Coord ob) {
    Coord temp;
    temp.x = x + ob.x;
    temp.y = x + ob.y;
    return temp;
}

Coord Coord::operator =(Coord ob) {
    x = ob.x + 100;
    y = ob.y + 100;
    return *this;
}

int main() {
    Coord a(10, 20), b(4, 4), c;
    int x, y;

    c = a++;
    c.getxy(x, y);
    cout << x << " " << y << endl;
    a.getxy(x, y);
    cout << x << " " << y << endl;

    c = ++a;
    c.getxy(x, y);
    cout << x << " " << y << endl;
    a.getxy(x, y);
    cout << x << " " << y << endl;

    (a*b).getxy(x, y);
    cout << x << " " << y << endl;

    if(4 == b) cout << "Equal" << endl;
    else cout << "Not equal" << endl;

    (20+a).getxy(x, y);
    cout << x << " " << y << endl;
    (a + b + c + 100).getxy(x, y);
    cout << x << " " << y << endl;

    c = a++;
    c.getxy(x, y);
    cout << x << " " << y << endl;
}