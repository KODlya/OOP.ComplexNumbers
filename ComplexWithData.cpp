#include "Complex.h"
#include "ComplexWithData.h"

ComplexWithData::ComplexWithData() :Complex() {
    Data();
}

ComplexWithData::ComplexWithData(double real, double im) : Complex(real, im) {
    Data();
}

ComplexWithData::ComplexWithData(const ComplexWithData& other) : Complex(other) {
    Data();
}

ComplexWithData::~ComplexWithData() {
    delete[] str;
    delete[] data;
}

char* ComplexWithData::GetData() {
    char* copy = new char[strlen(data)];
    strcpy(copy, data);
    return data;
}

void ComplexWithData::Data() {
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
        sprintf(data, "%d.%d.%d", ltm->tm_mday + 10, ltm->tm_mon + 1, ltm->tm_year + 1900);
    else
        sprintf(data, "%d.0%d.%d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}

ComplexWithData& ComplexWithData::operator = (ComplexWithData const& other) {
    Complex:: operator = (other);
    this->data = new char[strlen(other.data)];
    strcpy(this->data, other.data);
    return *this;
}

