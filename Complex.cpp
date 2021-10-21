#include "Complex.h"
#include <string>
#include <cstdlib>

Complex::Complex() {
    real = 0;
    im = 0;
    toString();
}

Complex::Complex(double real) {
    this->real = real;
    this->im = 0;
    toString();
}

Complex::Complex(double real, double im) {
    this->real = real;
    this->im = im;
    toString();
}

Complex::Complex(const Complex& other) {
    this->real = other.real;
    this->im = other.im;
    this->N = other.N;
    this->str = new char[other.N];
    strcpy(this->str,other.str);
}

double Complex::GetIm() {
    return im;
}

double Complex::GetReal() {
    return real;
}

char* Complex::GetStr() {
    char* copy = new char [this->N];
    strcpy(copy, str);
    return copy;
}

void Complex::SetIm(double im) {
    this->im = im;
    delete [] str;
    toString();
}

void Complex::SetReal(double real) {
    this->real = real;
    delete [] str;
    toString();
}

Complex::~Complex() {
    delete[] str;
}

Complex Complex:: Sum(Complex &val1, Complex &val2) {
    Complex temp(val1.real + val2.real, val1.im + val2.im);
    return temp;
}

Complex Complex::Dif(Complex &other) {
    Complex temp(this->real - other.real, this->im - other.im);
    return temp;
}

Complex Complex::Mult(Complex &other) {
    Complex temp(this->real * other.real - this->im * other.im, this->im * other.real + other.im * this->real);
    return temp;
}

Complex Complex::Div(Complex &other) {
    if (pow(other.real, 2) + pow(other.im, 2) == 0) {
        throw domain_error("Division by zero");
    }
    Complex temp((this->real * other.real + this->im * other.im) / (pow(other.real, 2) + pow(other.im, 2)), (this->im * other.real - other.im * this->real) / (pow(other.real, 2) + pow(other.im, 2)));
    return temp;
}

void Complex::toString() {
    if(str != nullptr)
        delete [] str;
    int  k = (int)real, p =(int) im;
    int n1 = 0, n2 = 0;

    do {
        k = k / 10;
        n1++;
    } while (k);

    do {
        p = p / 10;
        n2++;
    } while (p);

    if (real < 0)
        n1++;
    if (im < 0)
        n2++;

    n1 += 5;
    n2 += 5;
    if (im >= 0) {
        N = n1 + n2 + 3;
        str = new char[N];
        sprintf(str, "%.4f+%.4fi", real, im);
    }
    else {
        N = n1 + n2 + 5;
        str = new char[N];
        sprintf(str, "%.4f+(%.4f)i", real, im);
    }
}
Complex& Complex::operator = (Complex const &other) {
    if(this->str != nullptr){
        delete [] str;
    }
    this->real = other.real;
    this->im = other.im;
    this->N = other.N;
    this->str = new char[other.N];
    strcpy(this->str,other.str);
    return *this;
}

double Complex::Modul() {
    double m = sqrt(im*im+real*real);
    return m;
}

double Complex::Argument() {
    double arg;
    if(real == 0 && im > 0)
        arg = M_PI/2;
    if(real == 0 && im < 0)
        arg = -M_PI/2;
    else if(real > 0)
        arg = atan(im/real);
    else if(real < 0 && im > 0)
        arg = M_PI + atan(im/real);
    else if (real < 0 && im < 0){
        arg = -M_PI + atan(im/real);
    }
    return arg;
}

bool Complex::operator > (Complex &other) {
    return this->Modul() > other.Modul();
}

bool Complex::operator < (Complex &other) {
    return this->Modul() < other.Modul();
}

bool Complex::operator == (Complex &other) {
    return this->Modul() == other.Modul();
}

bool Complex::operator != (Complex &other) {
    return this->Modul() != other.Modul();
}

bool Complex::operator >= (Complex &other) {
    return this->Modul() >= other.Modul();
}

bool Complex::operator <= (Complex &other) {
    return this->Modul() <= other.Modul();
}

char* Complex::operator () () {
    double a = Modul(), b = Argument();
    int n1 = 0, n2 = 0;
    do {
        a = a / 10;
        n1++;
    } while ((int)a);

    do {
        b = b / 10;
        n2++;
    } while ((int)b);

    if(a < 0)
        n1++;
    if(b < 0)
        n2++;
    int K = n1 + n2 * 2 + 27;
    char* trg = new char[K];
    sprintf(trg, "%.4f*(cos(%.4f) + isin(%.4f))", Modul(), Argument(), Argument());
    return trg;
}

Complex operator / (Complex &val1, Complex &val2) {
    Complex temp = val1.Div(val2);
    return temp;
}

Complex operator * (Complex &val1, Complex &val2) {
    Complex temp = val1.Mult(val2);
    return temp;
}







