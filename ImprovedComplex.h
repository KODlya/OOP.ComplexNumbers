#ifndef PROGA_LAB_IMPROVEDCOMPLEX_H
#define PROGA_LAB_IMPROVEDCOMPLEX_H
#include "Complex.h"

class ImprovedComplex : public Complex {
public:
    ImprovedComplex();
    ImprovedComplex(double real, double im);
    ImprovedComplex(const ImprovedComplex& other);
    ImprovedComplex(char* str1);
    ~ImprovedComplex();
    void toVal(char* str1);
    ImprovedComplex& operator = (ImprovedComplex const& other);
};

#endif
