#include<iostream>

using namespace std;

class Box {
    double length;
    double width;
    double height;

public:
    Box() {
        length = 0;
        width = 0;
        height = 0;
    }

    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    Box(const Box &ob) {
        length = ob.length;
        width = ob.width;
        height = ob.height;
    }

    Box cpy(Box ob) {
        length = ob.length*2;
        width = ob.width*2;
        height = ob.height*2;
        return *this;
    }

    void show() {
        cout << length << " " << width << " " << height << endl;
    }

    double volume() {
        return length * width * height;
    }
    ~Box() {
        cout << "destructing " << length << endl;
    }
};

int main() {
    Box myBox(5, 3, 3);
    //Box myClone(myBox);
    Box newBox(2, 3, 5);

    newBox = newBox.cpy(newBox);


    cout << "Box volume: " << myBox.volume() << endl;
    //cout << "clone volume: " << myClone.volume() << endl;
    newBox.show();

}