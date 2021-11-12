#ifndef PROGA_LAB_LIST_H
#define PROGA_LAB_LIST_H

#include "Node.h"

template <typename T>

class List {
public:

    bool IsEmpty() {
        return(head == nullptr);
    }
    List () {
        head = nullptr;
    }

    void Insert(T &_t){
        auto * elem = new Node<T>(_t);
        elem->next = head;
        head = elem;
    }

    void InsertBack(T &_t) {
        auto * elem = new Node<T>(_t);
        Node<T> * tmp = head;
        if (IsEmpty()){
            head = elem;
            elem->next = nullptr;
        }
        else {
            while (tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = elem;
            elem->next = nullptr;
        }
    }

    T & operator[](int p) {
        Node<T> *tmp = head;
        for (int i = 0; i < p; i++) {
            if (tmp->next == nullptr)
                throw out_of_range("Out of list range");
            tmp = tmp->next;
        }
        return tmp->t;
    }

    void InsertByPosition(T &_t, int p) {
        if (p == 0)
            Insert(_t);
        else {
            Node<T>* tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            auto* elem = new Node<T>(_t);
            elem->next = tmp->next;
            tmp->next = elem;
        }
    }

    void DeleteByPosition(int p) {
        if (p == 0) {
            if (!IsEmpty()) {
                Node<T> *tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        else {
            Node<T> *tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            Node<T>* elem = tmp->next;
            tmp->next = tmp->next->next;
            delete elem;
        }
    }

private:
    Node<T>* head;
};


#endif //PROGA_LAB_LIST_H
