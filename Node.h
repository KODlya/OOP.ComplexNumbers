#ifndef PROGA_LAB_NODE_H
#define PROGA_LAB_NODE_H

#include "Complex.h"
#include "ComplexWithData.h"
#include "List.h"

struct Node {
    Node *next;
    Complex &complex;
    Node(Complex &_complex):next(nullptr), complex(_complex) {     }
    friend class List;
};


#endif //PROGA_LAB_NODE_H