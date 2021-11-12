#include "ImprovedComplex.h"
#include <string>

ImprovedComplex::ImprovedComplex() :Complex() {

}

ImprovedComplex::ImprovedComplex(double real, double im) : Complex(real, im) {

}

ImprovedComplex::ImprovedComplex(const ImprovedComplex& other) : Complex(other) {

}
ImprovedComplex::ImprovedComplex(char* str1) {
    strcpy(str, str1);
    toVal(str1);
}

void ImprovedComplex::toVal(char* str1) {
    stringstream istr;
    istr << str1;
    istr >> real;
    istr.ignore(256, '+');
    istr >> im;
    istr.ignore(256, 'i');
}

ImprovedComplex& ImprovedComplex::operator = (ImprovedComplex const& other) {
    Complex:: operator = (other);
    return *this;
}