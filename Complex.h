#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

class Complex {
public:
    Complex();
    Complex(double real, double im);
    Complex(const Complex& other);
    double GetReal();
    char* GetStr();
    double GetIm();
    void SetIm(double im);
    void SetReal(double real);
    ~Complex();
    static Complex Sum(Complex& val1, Complex& val2);
    Complex Dif(Complex& other);
    Complex Mult(Complex& other);
    Complex Div(Complex& other);
    double Modul();
    double Argument();
    Complex& operator = (Complex const& other);
    bool operator > (Complex& other);
    bool operator < (Complex& other);
    bool operator == (Complex& other);
    bool operator != (Complex& other);
    bool operator <= (Complex& other);
    bool operator >= (Complex& other);
    friend Complex operator * (Complex& val1, Complex& val2);
    friend Complex operator / (Complex& val1, Complex& val2);
    char* operator ()();
    friend ostream& operator << (ostream& os, Complex& val);
    friend istream& operator >> (istream& is, Complex& val);
    friend ofstream& BinaryIn(ofstream& os, Complex& val);
    friend ifstream& BinaryOut(ifstream& is, Complex& val);

protected:
    double real;
    double im;
    char* str = nullptr;
    int N;
    void toString();
};
#endif

