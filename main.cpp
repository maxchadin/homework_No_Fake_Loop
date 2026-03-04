#include <iostream>
#include "bilist.h"

int main() {
  BiList<char>* head = nullptr;
  BiList<char>* tail = nullptr;

  char arr[] = {'A', 'B', 'C', 'D'};
  int count = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < count; ++i) {
      push_back<char>(head, tail, arr[i]);
  }

  std::cout << "Список после конвертации массива: ";
  print_list<char>(head);

  clear_list<char>(head, tail);
  if (head == nullptr) {
      std::cout << "Память успешно очищена." << std::endl;
  }

  return 0;
}
