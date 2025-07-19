#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 0 ? 1 : a;
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (denominator == 0) {
            cout << "Denominator cannot be zero." << endl;
            return;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int num = 0, int den = 1) {
        if (den == 0) {
            cout << "denominator cannot be zero";
            exit(1);
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Division by zero fraction." << endl;
            exit(1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator+(float val) const {
        return *this + Fraction(val);
    }

    Fraction operator-(float val) const {
        return *this - Fraction(val);
    }

    Fraction operator*(float val) const {
        return *this * Fraction(val);
    }

    Fraction operator/(float val) const {
        if (val == 0.0f) {
            cout << "Division by zero float." << endl;
            exit(1);
        }
        return *this / Fraction(val);
    }

    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    Fraction& operator+=(float val) {
        *this = *this + val;
        return *this;
    }

    Fraction& operator-=(float val) {
        *this = *this - val;
        return *this;
    }

    Fraction& operator*=(float val) {
        *this = *this * val;
        return *this;
    }

    Fraction& operator/=(float val) {
        *this = *this / val;
        return *this;
    }

    explicit Fraction(float val) {
        const int precision = 100000;
        numerator = static_cast<int>(round(val * precision));
        denominator = precision;
        simplify();
    }

    friend Fraction operator+(float val, const Fraction& frac) {
        return Fraction(val) + frac;
    }

    friend Fraction operator-(float val, const Fraction& frac) {
        return Fraction(val) - frac;
    }

    friend Fraction operator*(float val, const Fraction& frac) {
        return Fraction(val) * frac;
    }

    friend Fraction operator/(float val, const Fraction& frac) {
        if (frac.numerator == 0) {
            cout << "Division by zero fraction." << endl;
            exit(1);
        }
        return Fraction(val) / frac;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

class FractionVector {
private:
    Fraction* data;
    int size;

public:
    FractionVector() {
        size = 0;
        data = nullptr;
    }
    explicit FractionVector(int n) {
        size = n;
        data = new Fraction[n];
    }

    FractionVector(const FractionVector& other) {
        size = other.size;
        data = new Fraction[other.size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    FractionVector& operator=(const FractionVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new Fraction[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }


    ~FractionVector() {
        delete[] data;
    }


    int getSize() const { 
        return size; 
    }

    Fraction& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            exit(1);
        }
        return data[index];
    }


    const Fraction& operator[] (int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            exit(1);
        }
        return data[index];
    }

    FractionVector operator+(const FractionVector& other) const {
        if (size != other.size) {
            cout << "Vector size mismatch for addition." << endl;
            exit(1);
        }
        FractionVector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = data[i] + other.data[i];
        }
        return result;
    }

    FractionVector operator-(const FractionVector& other) const {
        if (size != other.size) {
            cout << "Vector size mismatch for subtraction." << endl;
            exit(1);
        }
        FractionVector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = data[i] - other.data[i];
        }
        return result;
    }

    FractionVector operator*(const Fraction& scalar) const {
        FractionVector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = data[i] * scalar;
        }
        return result;
    }

    FractionVector operator/(const Fraction& scalar) const {
        FractionVector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = data[i] / scalar;
        }
        return result;
    }

    friend FractionVector operator*(const Fraction& scalar, const FractionVector& vec) {
        return vec * scalar;
    }

    Fraction operator*(const FractionVector& other) const {
        if (size != other.size) {
            cout << "Vector size mismatch for dot product." << endl;
            exit(1);
        }
        Fraction result(0, 1);
        for (int i = 0; i < size; ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    float value() const {
        float sum = 0.0f;
        for (int i = 0; i < size; ++i) {
            float val = static_cast<float>(data[i].getNumerator()) / data[i].getDenominator();
            sum += val * val;
        }
        return sqrt(sum);
    }

    friend ostream& operator<<(ostream& os, const FractionVector& vec) {
        os << "[ ";
        for (int i = 0; i < vec.size; ++i) {
            os << vec.data[i] << " ";
        }
        os << "]";
        return os;
    }
};

class FractionMatrix {
private:
    int rows, cols;
    FractionVector* rowData;
    FractionVector* colData;

public:
    FractionMatrix(int r = 0, int c = 0) {
        rows = r;
        cols = c;
        rowData = new FractionVector[r];
        for (int i = 0; i < rows; ++i) {
            rowData[i] = FractionVector(cols);
        }

        colData = new FractionVector[c];
        for(int i = 0; i < cols; ++i) {
            colData[i] = FractionVector(rows);
        }
    }

    FractionMatrix(const FractionMatrix& other) {
        rows = other.rows;
        cols = other.cols;
        rowData = new FractionVector[other.rows];

        for (int i = 0; i < rows; ++i) {
            rowData[i] = other.rowData[i];
        }

        colData = new FractionVector[other.cols];
        for(int i = 0; i < cols; ++i) {
            colData[i] = other.colData[i];
        }
    }

    FractionMatrix& operator=(const FractionMatrix& other) {
        if (this != &other) {
            delete[] rowData;
            rows = other.rows;
            cols = other.cols;
            rowData = new FractionVector[rows];
            for (int i = 0; i < rows; ++i) {
                rowData[i] = other.rowData[i];
            }
        }
        return *this;
    }

    ~FractionMatrix() {
        delete[] rowData;
    }

    FractionVector& operator[](int index) {
        if (index < 0 || index >= rows) {
            cout << "Row index out of bounds." << endl;
            exit(1);
        }
        return rowData[index];
    }

    const FractionVector& operator[](int index) const {
        if (index < 0 || index >= rows) {
            cout << "Row index out of bounds." << endl;
            exit(1);
        }
        return rowData[index];
    }

    FractionVector getColumn(int index) const {
        if (index < 0 || index >= cols) {
            cout << "Column index out of bounds." << endl;
            exit(1);
        }
        FractionVector column(rows);
        for (int i = 0; i < rows; ++i) {
            column[i] = rowData[i][index];
        }
        return column;
    }

    FractionMatrix operator+(const FractionMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions do not match for addition." << endl;
            exit(1);
        }
        FractionMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result[i] = rowData[i] + other.rowData[i];
        }
        return result;
    }

    FractionMatrix operator-(const FractionMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions do not match for subtraction." << endl;
            exit(1);
        }
        FractionMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result[i] = rowData[i] - other.rowData[i];
        }
        return result;
    }

    FractionMatrix operator*(const Fraction& scalar) const {
        FractionMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result[i] = rowData[i] * scalar;
        }
        return result;
    }

    friend FractionMatrix operator*(const Fraction& scalar, const FractionMatrix& matrix) {
        return matrix * scalar;
    }

    FractionMatrix operator/(const Fraction& scalar) const {
        FractionMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result[i] = rowData[i] / scalar;
        }
        return result;
    }

    FractionMatrix operator*(const FractionMatrix& other) const {
        if (cols != other.rows) {
            cout << "Matrix dimensions not match for multiplication." << endl;
            exit(1);
        }
        FractionMatrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                Fraction sum(0, 1);
                for (int k = 0; k < cols; ++k) {
                    sum += rowData[i][k] * other.rowData[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    FractionMatrix operator%(const FractionMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions do not match for Hadamard product." << endl;
            exit(1);
        }
        FractionMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = rowData[i][j] * other.rowData[i][j];
            }
        }
        return result;
    }

    FractionMatrix transpose() const {
        FractionMatrix result(cols, rows);
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result[i][j] = rowData[j][i];
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const FractionMatrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            os << matrix.rowData[i] << endl;
        }
        return os;
    }
};

int main() {
    cout << "=== FRACTION OPERATIONS ===" << endl;
    Fraction f1(1, 2), f2(3, 4), f3;
    cout << "f1 = " << f1 << ", f2 = " << f2 << endl;

    f3 = f1 + f2;
    cout << "f1 + f2 = " << f3 << endl;

    f3 = f1 - f2;
    cout << "f1 - f2 = " << f3 << endl;

    f3 = f1 * f2;
    cout << "f1 * f2 = " << f3 << endl;

    f3 = f1 / f2;
    cout << "f1 / f2 = " << f3 << endl;

    f3 = f1 + 1.5f;
    cout << "f1 + 1.5 = " << f3 << endl;

    f3 = 1.5f + f1;
    cout << "1.5 + f1 = " << f3 << endl;

    cout << "\n=== VECTOR OPERATIONS ===" << endl;
    FractionVector v1(3), v2(3);
    v1[0] = Fraction(1, 2); v1[1] = Fraction(2, 3); v1[2] = Fraction(3, 4);
    v2[0] = Fraction(4, 5); v2[1] = Fraction(5, 6); v2[2] = Fraction(6, 7);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    FractionVector v_add = v1 + v2;
    cout << "v1 + v2 = " << v_add << endl;

    Fraction scalar(2, 1);
    FractionVector v_scalar_mul = v1 * scalar;
    cout << "v1 * 2 = " << v_scalar_mul << endl;

    Fraction dot = v1 * v2;
    cout << "v1 · v2 = " << dot << endl;

    cout << "||v1|| = " << v1.value() << endl;

    cout << "\n=== MATRIX OPERATIONS ===" << endl;
    FractionMatrix m1(2, 2), m2(2, 2);
    m1[0][0] = Fraction(1, 2); m1[0][1] = Fraction(2, 3);
    m1[1][0] = Fraction(3, 4); m1[1][1] = Fraction(4, 5);

    m2[0][0] = Fraction(5, 6); m2[0][1] = Fraction(6, 7);
    m2[1][0] = Fraction(7, 8); m2[1][1] = Fraction(8, 9);

    cout << "Matrix m1:\n" << m1;
    cout << "Matrix m2:\n" << m2;

    FractionMatrix m_add = m1 + m2;
    cout << "m1 + m2 =\n" << m_add;

    FractionMatrix m_sub = m1 - m2;
    cout << "m1 - m2 = \n" << m_sub;

    FractionMatrix m_scalar_mul = m1 * Fraction(2, 1);
    cout << "m1 * 2 =\n" << m_scalar_mul;

    FractionMatrix m_mul = m1 * m2;
    cout << "m1 * m2 =\n" << m_mul;

    FractionMatrix m_hadamard = m1 % m2;
    cout << "m1 % m2 (Hadamard) =\n" << m_hadamard;

    FractionMatrix m_transpose = m1.transpose();
    cout << "Transpose of m1 =\n" << m_transpose;

    return 0;
}