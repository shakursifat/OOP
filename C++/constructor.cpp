#include<iostream>

using namespace std;

class Myclass {
    int a = 0;
public:
    Myclass() {
        cout << "No argument constructor" << endl;
    }
    void show();
    Myclass(int newA);
    ~Myclass() {
        cout << "destructing" << endl;
    }
    
};

Myclass::Myclass(int newA) {
    cout << "constructor with argument" << endl;
    a = newA;
}

void Myclass::show() {
    cout << a << "\n";
}

int main() {
    Myclass ob1, ob2(10);

    ob1.show();
    ob2.show();

}