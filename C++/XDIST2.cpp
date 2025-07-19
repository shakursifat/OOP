#include<iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    class InchesEx {
    public:
        string errorname;
        float errorval;

        InchesEx(string errorname, float errorval) {
            this->errorname = errorname;
            this->errorval = errorval;
        }
    };

    Distance() {
        feet = 0;
        inches = 0.0;
    }

    Distance(int ft, float in) {
        if(in >= 12.0) {
            throw InchesEx("constructor problem", in);
        }

        feet = ft;
        inches = in;
    }

    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;

        if(inches >= 12.0) {
            throw InchesEx("user input error", inches);
        }
    }

    void showdist() {
        cout << feet << " " << inches << endl;
    }
};

int main() {
    try{
        Distance dist1(17, 3.5);
        Distance dist2;
        dist2.getdist();

        cout << "dist1 = " ;
        dist1.showdist();
        cout << "dist2 = " ;
        dist2.showdist();
    }
    catch(Distance::InchesEx inch) {
        cout << inch.errorname << " " << inch.errorval << endl;
    }
}