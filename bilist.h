#ifndef BILIST_H
#define BILIST_H

#include <iostream>
#include <stdexcept>

template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template< class T >
BiList<T>* push_back(BiList<T>* head, const T& value) {
  try {
    BiList<T>* newNode = new BiList<T>;
    newNode->val = value;
    newNode->next = nullptr;
    if (!head) {
      newNode->prev = nullptr;
      return newNode;
    }
    BiList<T>* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    return head;
  } catch (const std::bad_alloc&) {
    throw;
  }
}

template< class T >
BiList<T>* push_front(BiList<T>* head, const T& value) {
  try {
    BiList<T>* newNode = new BiList<T>;
    newNode->val = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
  } catch (const std::bad_alloc&) {
    throw;
  }
}

template< class T >
BiList<T>* remove_val(BiList<T>* head, const T& value) {
  BiList<T>* curr = head;
  while (curr) {
    if (curr->val == value) {
      if (curr->prev) curr->prev->next = curr->next;
      if (curr->next) curr->next->prev = curr->prev;
      BiList<T>* newHead = (curr == head) ? curr->next : head;
      delete curr;
      return newHead;
    }
    curr = curr->next;
  }
  return head;
}

template< class T >
void print_list(BiList<T>* head) {
  BiList<T>* curr = head;
  while (curr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

template< class T >
BiList<T>* clear_list(BiList<T>* head) {
  while (head) {
    BiList<T>* temp = head;
    head = head->next;
    delete temp;
  }
  return nullptr;
}

#endif
