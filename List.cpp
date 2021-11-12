#include "List.h"

bool List::IsEmpty() {
    return(head == nullptr);
}
List::List (){
   head = nullptr;
}

void List::Insert(Complex &_complex){
   Node * elem = new Node(_complex);
   elem->next = head;
   head = elem;
}

void List::InsertBack(Complex &_complex) {
    Node * elem = new Node(_complex);
    Node * tmp = head;
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

Complex &List::operator[](int p) {
    Node *tmp = head;
    for (int i = 0; i < p; i++) {
        if (tmp->next == nullptr)
            throw out_of_range("Out of list range");
        tmp = tmp->next;
    }
    return tmp->complex;
}

void List::InsertByPosition(Complex &_complex, int p) {
    if (p == 0)
        Insert(_complex);
    else {
        Node* tmp = head;
        for (int i = 0; i < p-1; i++) {
            if (tmp->next == nullptr)
                throw out_of_range("Out of list range");
            tmp = tmp->next;
        }
        Node* elem = new Node(_complex);
        elem->next = tmp->next;
        tmp->next = elem;
    }
}

void List::DeleteByPosition(int p) {
    if (p == 0) {
        if (!IsEmpty()) {
            Node *tmp = head->next;
            delete head;
            head = tmp;
        }
    }
    else {
        Node *tmp = head;
        for (int i = 0; i < p-1; i++) {
            if (tmp->next == nullptr)
                throw out_of_range("Out of list range");
            tmp = tmp->next;
        }
        Node* elem = tmp->next;
        tmp->next = tmp->next->next;
        delete elem;
    }
}
