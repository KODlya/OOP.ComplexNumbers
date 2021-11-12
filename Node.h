#ifndef PROGA_LAB_NODE_H
#define PROGA_LAB_NODE_H

#include "Complex.h"
#include "List.h"

class Node {
    Node *next;
    Complex complex;
    Node(Complex &_complex) {
        next = nullptr;
        complex = Complex(_complex);
    }
    friend class List;
};


#endif //PROGA_LAB_NODE_H
