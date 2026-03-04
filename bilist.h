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
