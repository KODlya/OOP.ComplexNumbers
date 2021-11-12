#ifndef PROGA_LAB_NODE_H
#define PROGA_LAB_NODE_H

#include "Complex.h"

template <typename T>
struct Node {
    Node *next;
    T t;
    Node(T &_t) {
        next = nullptr;
        t = _t;
    }
};


#endif //PROGA_LAB_NODE_H
