#ifndef BILIST_H
#define BILIST_H

#include <iostream>

template< class T >
struct BiList {
    T val;
    BiList<T> * next;
    BiList<T> * prev;
};

template< class T >
void push_back(BiList<T>* &head, BiList<T>* &tail, T value) {
    BiList<T>* newNode = new BiList<T>;
    newNode->val = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // Если список пуст
    }
    tail = newNode;
}

template< class T >
void print_list(BiList<T>* head) {
    BiList<T>* current = head;
    while (current != nullptr) {
        std::cout << "[" << current->val << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

template< class T >
void clear_list(BiList<T>* &head, BiList<T>* &tail) {
    BiList<T>* current = head;
    while (current != nullptr) {
        BiList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

#endif
