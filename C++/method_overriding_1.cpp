#include<iostream>
#include<string.h>

using namespace std;

class Father {
    char name[20];
public:
    Father(char *fname) {
        strcpy(name, fname);
    }

    virtual void show() {
        cout << "Father: " << name << endl;
    }
};

class Son : public Father {
    char name[20];
public:
    Son(char *sname, char *fname) : Father(fname) {
        strcpy(name, sname);
    }

    /*void show() {
        cout << "Son: " << name << endl;
    }*/
};

int main() {
    Father *fp, father("Rashid");
    Son son("Robin", "Rashid");
    fp = &father;
    cout << fp << endl;
    fp->show();
    fp = &son;
    cout << fp << endl;
    fp->show();
    son.show();
}