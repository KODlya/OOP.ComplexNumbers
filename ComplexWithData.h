#ifndef COMPLEXWD_H
#define COMPLEXWD_H
#include "Complex.h"
#include <ctime>
#include <cstdlib>

class DataComplex : public Complex {
public:
    DataComplex();
    DataComplex(double real, double im);
    DataComplex(const DataComplex& other);
    ~DataComplex();
    void Data();
    char* GetData();
    DataComplex& operator = (DataComplex const& other);
private:
    char* data;
};

#endif



