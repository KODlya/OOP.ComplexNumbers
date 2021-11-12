#ifndef PROGA_LAB_LIST_H
#define PROGA_LAB_LIST_H

#include "Node.h"

class List {
public:
    List();
    bool IsEmpty();
    void Insert(Complex &_complex);
    Complex& operator[](int i);
    void InsertBack(Complex &_complex);
    void InsertByPosition(Complex &_complex, int p);
    void DeleteByPosition(int pos);
private:
    Node* head;
};


#endif //PROGA_LAB_LIST_H