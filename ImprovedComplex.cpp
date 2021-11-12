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

ImprovedComplex operator * (ImprovedComplex& val1, ImprovedComplex& val2) {
    Complex temp1 = val1.Mult(val2);
    ImprovedComplex temp(temp1.GetReal(),temp1.GetIm());
    return temp;
}

ImprovedComplex operator / (ImprovedComplex& val1, ImprovedComplex& val2) {
    Complex temp1 = val1.Div(val2);
    ImprovedComplex temp(temp1.GetReal(),temp1.GetIm());
    return temp;
}