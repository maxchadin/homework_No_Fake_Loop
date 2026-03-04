#include <iostream>
#include "BiList.h"

int main() {
  BiList<char>* head = nullptr;

  try {
    char arr[] = {'A', 'B', 'C', 'D'};
    int count = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < count; ++i) {
      head = push_back(head, arr[i]);
    }

    print_list(head);

  } catch (...) {
    return 1;
  }

  head = clear_list(head);

  return 0;
}
