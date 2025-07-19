#include<iostream>
#include<cstring>

using namespace std;

class Samp {
    char *s;
public:
    Samp() { s = '\0';}
    ~Samp() {
        free(s);
        cout << "freeing S\n";
    }

    // Samp& operator=(const Samp &ob) {
    //     if(this == &ob) {
    //         return *this;
    //     }
    //     s = (char*)malloc(strlen(ob.s)+1);
    //     strcpy(s, ob.s);
    //     return *this;
    // }
    

    void show() {
        cout << s << endl;
    }

    void set(char *str) {
        s = (char*) malloc(strlen(str)+1);
        strcpy(s, str);
    }
};

Samp input() {
    Samp s;
    s.set("Hello world");
    return s;
}

int main() {
    Samp ob;
    ob = input();
    ob.show();
}