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

template<>
class List<int> {
public:
    static int Max(int n1, int n2) {
        if(n1 > n2)
            return n1;
        else
            return n2;
    }

    bool IsEmpty() {
        return(head == nullptr);
    }
    List () {
        head = nullptr;
    }

    void Insert(int &_t){
        auto * elem = new Node<int>(_t);
        elem->next = head;
        head = elem;
    }

    void InsertBack(int &_t) {
        auto * elem = new Node<int>(_t);
        Node<int> * tmp = head;
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

    int & operator[](int p) {
        Node<int> *tmp = head;
        for (int i = 0; i < p; i++) {
            if (tmp->next == nullptr)
                throw out_of_range("Out of list range");
            tmp = tmp->next;
        }
        return tmp->t;
    }

    void InsertByPosition(int &_t, int p) {
        if (p == 0)
            Insert(_t);
        else {
            Node<int>* tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            auto* elem = new Node<int>(_t);
            elem->next = tmp->next;
            tmp->next = elem;
        }
    }

    void DeleteByPosition(int p) {
        if (p == 0) {
            if (!IsEmpty()) {
                Node<int> *tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        else {
            Node<int> *tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            Node<int>* elem = tmp->next;
            tmp->next = tmp->next->next;
            delete elem;
        }
    }

private:
    Node<int>* head;
};


template<>
class List<float> {
public:
    static float Min(float n1, float n2) {
        if(n1 < n2)
            return n1;
        else
            return n2;
    }

    bool IsEmpty() {
        return(head == nullptr);
    }

    List () {
        head = nullptr;
    }

    void Insert(float &_t){
        auto * elem = new Node<float>(_t);
        elem->next = head;
        head = elem;
    }

    void InsertBack(float &_t) {
        auto * elem = new Node<float>(_t);
        Node<float> * tmp = head;
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

    float & operator[](int p) {
        Node<float> *tmp = head;
        for (int i = 0; i < p; i++) {
            if (tmp->next == nullptr)
                throw out_of_range("Out of list range");
            tmp = tmp->next;
        }
        return tmp->t;
    }

    void InsertByPosition(float &_t, int p) {
        if (p == 0)
            Insert(_t);
        else {
            Node<float>* tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            auto* elem = new Node<float>(_t);
            elem->next = tmp->next;
            tmp->next = elem;
        }
    }

    void DeleteByPosition(int p) {
        if (p == 0) {
            if (!IsEmpty()) {
                Node<float> *tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        else {
            Node<float> *tmp = head;
            for (int i = 0; i < p-1; i++) {
                if (tmp->next == nullptr)
                    throw out_of_range("Out of list range");
                tmp = tmp->next;
            }
            Node<float>* elem = tmp->next;
            tmp->next = tmp->next->next;
            delete elem;
        }
    }

private:
    Node<float>* head;
};
#endif //PROGA_LAB_LIST_H
