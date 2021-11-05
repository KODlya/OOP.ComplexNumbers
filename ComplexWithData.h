#ifndef COMPLEXWD_H
#define COMPLEXWD_H
#include "Complex.h"
#include <ctime>
#include <cstdlib>

class ComplexWithData : public Complex {
public:
    ComplexWithData();
    ComplexWithData(double real, double im);
    ComplexWithData(const ComplexWithData& other);
    ~ComplexWithData();
    void Data();
    char* GetData();
    ComplexWithData& operator = (ComplexWithData const& other);
private:
    char* data;
};

#endif



