#include <iostream>
#include <string.h>

using namespace std;

typedef struct xx {
    private:
        string name;
        int rollno;
        double cgpa;
    public:
        void setName(string N) { name = N;}
        string getName() {return name;}
        void setRollno(int R) { rollno = R;}
        int getRollno() {return rollno;}
        void setCGPA(double CGPA) { cgpa = CGPA;}
        double getCGPA() { return cgpa;}
} Student;

int main() {
    Student karim;
    string iname;
    int irollno;
    double icgpa;

    cout << "Enter the name: ";
    getline(cin, iname);
    karim.setName(iname);

    cout << "Enter Rollno: ";
    cin >> irollno;
    karim.setRollno(irollno);

    cout << "Enter CGPA: ";
    cin >> icgpa;
    karim.setCGPA(icgpa);

    cout << karim.getName() << " ";
    cout << karim.getRollno();
    cout << " " << karim.getCGPA();
}