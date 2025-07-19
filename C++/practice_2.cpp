#include<iostream>
using namespace std;

class Myclass {
    int x;
public:
    Myclass() {
        x = 0;
        cout << "Constructor" << endl;
    }
    ~Myclass() {
        cout << "Destructor" << endl;
    }
    void setX(int val) { x = val;}
    int& getX() {return x;}
    
};

inline void modifyValue(Myclass &obj) {
    obj.getX() = 100;
}

int main() {
    Myclass obj1;
    obj1.setX(50);
    int& ref = obj1.getX();
    ref = 75;
    modifyValue(obj1);
    cout << obj1.getX() << endl;

}