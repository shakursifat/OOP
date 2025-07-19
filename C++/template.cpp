#include<iostream>
using namespace std;

template <class T>
class Gen {
    T val;
public:
    Gen(T v) {
        val = v;
    }
    T getval() {
        return val;
    }
};

int main() {
    Gen<int> iob(88);
    Gen<double> dob(22.22);
    Gen<char> cob('X');

    cout << "value: " << iob.getval() << endl;
    cout << "value: " << dob.getval() << endl;
    cout << "value: " << cob.getval() << endl;
}