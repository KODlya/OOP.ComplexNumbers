#include "Complex.h"
#include "ComplexWithData.h"

DataComplex::DataComplex() :Complex() {
    Data();
}

DataComplex::DataComplex(double real, double im) : Complex(real, im) {
    Data();
}

DataComplex::DataComplex(const DataComplex& other) : Complex(other) {
    Data();
}

DataComplex::~DataComplex() {
    delete[] data;
}

char* DataComplex::GetStr() {
    char* copy = new char[strlen(data)];
    strcpy(copy, data);
    return copy;
}

char* DataComplex::GetStrCmp() {
    char* copy = new char[strlen(str)];
    strcpy(copy, str);
    return copy;
}

void DataComplex::Data() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    data = new char[10];
    if ((ltm->tm_mday) < 10)
        if (ltm->tm_mon + 1 >= 10)
            sprintf(data, "0%d.%d.%d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
        else
            sprintf(data, "0%d.0%d.%d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    else
    if (ltm->tm_mon + 1 > 10)
        sprintf(data, "%d.%d.%d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    else
        sprintf(data, "%d.0%d.%d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}

DataComplex& DataComplex::operator = (DataComplex const& other) {
    Complex:: operator = (other);
    this->data = new char[strlen(other.data)];
    strcpy(this->data, other.data);
    return *this;
}
