#include<iostream>
#include<climits>


using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;
    int cpy_numerator;
    int cpy_denominator;
public:
    Fraction() {
        numerator = 1;
        denominator = 1;
        cpy_numerator = numerator;
        cpy_denominator = denominator;
    }

    Fraction(int numerator) {
        this->numerator = numerator;
        denominator = 1;
        cpy_numerator = this->numerator;
        cpy_denominator = denominator;
    }

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
        cpy_numerator = this->numerator;
        cpy_denominator = this->denominator;
    }

    //Fraction(const Fraction &ob) = default;

    ~Fraction() {
    }

    

    void cpy() {
        cpy_numerator = numerator;
        cpy_denominator = denominator;
    }


    Fraction add(Fraction &f) {
        this->cpy();

        this->cpy_numerator = this->numerator*f.denominator + this->denominator*f.numerator;
        this->cpy_denominator = this->denominator*f.denominator;
        return *this;
    }

    Fraction add(int n) {
        this->cpy();
        this->cpy_numerator += n*denominator;
        return *this;
    }

    Fraction sub(Fraction &f) {
        this->cpy();

        this->cpy_numerator = this->numerator*f.denominator - this->denominator*f.numerator;
        this->cpy_denominator = this->denominator*f.denominator;
        return *this;
    }

    Fraction sub(int n) {
        this->cpy();
        this->cpy_numerator -= n*denominator;
        return *this;
    }

    Fraction mul(Fraction &f) {
        this->cpy();

        this->cpy_numerator = this->numerator*f.numerator;
        this->cpy_denominator = this->denominator*f.denominator;
        return *this;
    }

    Fraction mul(int n) {
        this->cpy();
        this->cpy_numerator *= n;
        return *this;
    }

    Fraction div(Fraction &f) {
        this->cpy();

        this->cpy_numerator = this->numerator*f.denominator;
        this->cpy_denominator = this->denominator*f.numerator;
        return *this;
    }

    Fraction div(int n) {
        if(n == 0) {
            cout << "Can not divide by 0" << endl;
            this->cpy();
            return *this;
        }
        this->cpy();
        this->cpy_denominator *= n;
        return *this;
    }

    void print() {
        //this->cpy();
        int x = cpy_denominator;
        for(int i = 1; i <= x; i++) {
            if(this->cpy_numerator % i == 0 && this->cpy_denominator % i == 0) {
                this->cpy_numerator /= i;
                this->cpy_denominator /= i;
                i = 1;
            }
        }

        cout << cpy_numerator << "/" << cpy_denominator << endl;
    }

};


class FractionCollection{
    Fraction* fractions;
    int maxlength;
    int length;
    Fraction** fractions_ptr;
public:
    FractionCollection() {
        fractions = new Fraction[10];
        fractions_ptr = new Fraction*[10];
        maxlength = 10;
        length = 0;
    }

    FractionCollection(int maxlength) {
        fractions = new Fraction[maxlength];
        fractions_ptr = new Fraction*[maxlength];
        this->maxlength = maxlength;
        length = 0;
    }

    ~FractionCollection() {
        delete[] fractions;
        delete[] fractions_ptr;
    }

    void insert(Fraction *f) {
        fractions[length] = *f;
        fractions_ptr[length] = f;
        length++;
    }

    void insert(int pos, Fraction *f) {
        for(int i = length; i > pos; i--) {
            fractions[i] = fractions[i-1];
            fractions_ptr[i] = fractions_ptr[i-1];
        }
        fractions[pos] = *f;
        fractions_ptr[pos] = f;
        length++;
    }

    void remove() {
        fractions[length] = 0;
        length--;
    }

    void remove(Fraction *f) {
        int found = 0;
        for(int i = 0; i < length; i++) {
            if(fractions_ptr[i] == f) {
                fractions[i] = fractions[i+1];
                fractions_ptr[i] = fractions_ptr[i+1];
                found = 1;
            }
            if(found == 1) {
                fractions[i] = fractions[i+1];
                fractions_ptr[i] = fractions_ptr[i+1];
            }
        }
        length--;
    }

    void remove(int pos) {
        int found = 0;
        for(int i = 0; i < length; i++) {
            if(i == pos) {
                fractions[i] = fractions[i+1];
                fractions_ptr[i] = fractions_ptr[i+1];
                found = 1;
            }
            if(found == 1) {
                fractions[i] = fractions[i+1];
                fractions_ptr[i] = fractions_ptr[i+1];
            }
        }
        length--;
    }

    Fraction getmax() {
        double max = INT_MIN;
        int mx_indx = 0;
        for(int i = 0; i < length; i++) {
            double x = fractions[i].numerator/fractions[i].denominator;
            if(x > max) {
                max = x;
                mx_indx = i;
            }
        }
        return fractions[mx_indx];
    }

    Fraction getmin() {
        double min = INT_MAX;
        int min_indx = 0;
        for(int i = 0; i < length; i++) {
            double x = fractions[i].numerator/fractions[i].denominator;
            if(x < min) {
                min = x;
                min_indx = i;
            }
        }
        return fractions[min_indx];
    }

    Fraction temp;

    Fraction add(int start, int end) {
        int x = 0, y = 1;
        for(int i = start; i <= end; i++) {
            x = x*fractions[i].denominator + y*fractions[i].numerator;
            y = y*fractions[i].denominator;
        }
        Fraction temp(x, y);
        return temp;
    }

    Fraction mul(int start, int end) {
        int x = 1, y = 1;
        for(int i = start; i <= end; i++) {
            x *= fractions[i].numerator;
            y *= fractions[i].denominator;
        }
        Fraction temp(x, y);
        return temp;
    }

    Fraction sub(int pos1, int pos2) {
        int x, y;
        x = fractions[pos1].numerator*fractions[pos2].denominator - fractions[pos1].denominator*fractions[pos2].numerator;
        y = fractions[pos1].denominator*fractions[pos2].denominator;
        Fraction temp(x, y);
        return temp;
    }

    Fraction div(int pos1, int pos2) {
        int x, y;
        x = fractions[pos1].numerator*fractions[pos2].denominator;
        y = fractions[pos1].denominator*fractions[pos2].numerator;
        Fraction temp(x, y);
        return temp;
    }


    void print() {
        for(int i = 0; i < length; i++) {
            fractions[i].cpy();
            cout << "Fraction " << i << ": ";
            int x = fractions[i].cpy_denominator;
            for(int j = 1; j <= x; j++) {
                if(fractions[i].cpy_numerator % j == 0 && fractions[i].cpy_denominator % j == 0) {
                    fractions[i].cpy_numerator /= j;
                    fractions[i].cpy_denominator /= j;
                    j = 1;
                }
            }
            cout << fractions[i].cpy_numerator << "/" << fractions[i].cpy_denominator << endl;
        }

    }
};

int main() {
    Fraction a(5,2), b(7,2), c(9,2), d(28,5);
    cout << "Fraction" << endl;
    cout << "-------------------------------" << endl;
    cout << "A: ";
    a.print();
    cout<<"B: ";
    b.print();
    cout<<endl;

    cout<<"Add(a,b): ";
    a.add(b).print();
    cout<<"Add(a,2): ";
    a.add(2).print();

    cout<<"Sub(a,b) "; 
    a.sub(b).print(); 
    cout<<"Sub(a,2) "; 
    a.sub(2).print();

    cout<<"Mul(a,b): "; 
    a.mul(b).print(); 
    cout<<"Mul(a,2): "; 
    a.mul(2).print();

    cout<<"Div(a,b): "; 
    a.div(b).print(); 
    cout<<"Div(a,2): "; 
    a.div(2).print(); 
    cout<<"Div(a,0): ";
    a.div(0).print();
    cout << endl;

    cout << "Fractions" << endl;
    cout << "-------------------------------" << endl;

    Fraction e,f(5),g(10); 
    FractionCollection fc(10); 
    fc.insert(&a); 
    fc.insert(&b); 
    fc.insert(&c); 
    fc.print();


    cout << "Max: " ;
    fc.getmax().print();
    cout << "Min: " ;
    fc.getmin().print();
    cout << endl;

    cout<< "Sub(Pos0, Pos1): "; 
    fc.sub(0,1).print(); //subtracts the fraction at pos1 from fraction at pos0

    cout<<"Div(Pos0, Pos1): "; 
    fc.div(0,1).print(); //divides the fraction at pos0 by the fraction at pos1

    cout<< "Add(): ";
    fc.add(0, 2).print();

    cout << "Mul(): ";
    fc.mul(0, 2).print();

    cout << endl;
    fc.print();
    cout << endl;
    fc.remove(1); //removed 'b' 
    fc.print();
    cout << endl;
    fc.remove(&a); //removed 'a'
    fc.print();
    cout << endl;
    fc.insert(&d);
    fc.insert(0,&e); //insert at pos0
    fc.insert(&f);
    fc.insert(&g);
    fc.print();
    cout << endl;
    fc.remove(); //removed the last fraction 
    fc.print(); //notice the output


}