#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    cout << v[2] << endl;
    cout << v[10];
    try {
        cout << v[10];
    } catch(out_of_range e) {
        cout << "exception caught: " << e.what() << endl;
    }
}