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
    char * GetStr() override;
    char * GetStrCmp();
    void Data();
    DataComplex& operator = (DataComplex const& other);
private:
    char* data;
};

#endif