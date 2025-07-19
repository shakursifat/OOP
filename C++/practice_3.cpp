#include<iostream>
using namespace std;

template<class atype, int num = 1>
class myclass {
    atype data;
public:
    myclass(atype data) {
        this->data = data*num;
    }

    atype getx() {
        return data;
    }
};

int main(){
    myclass<double> d1(1.1);
    myclass<double, 2> d2(1.1);
    myclass<double, 3> d3(1.1);
    cout << d1.getx() << " " << d2.getx() << " " << d3.getx() << endl;

    myclass<int, 4> i1(5);
    myclass<int> i2(5);
    cout << i1.getx() << " " << i2.getx() << endl;

}

/*template<class atype, int num = 1>
class myclass {
    atype data;
public:
    myclass(atype data) {
        this->data = data*num;
    }

    atype getx() {
        return data;
    }
};*/    