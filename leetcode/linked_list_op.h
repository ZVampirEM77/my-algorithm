#include <iostream>
#include <time.h>

template <class T>
T* CreateLinkedList(int n) {
    if (!n) {
        return nullptr;
    }

    srand((unsigned int)time(NULL));
    T * head = new T(rand());
    T * cur_node = head;

    for (int i = 1; i < n; i++) {
        cur_node->next = new T(rand());
        cur_node = cur_node->next;
    }

    return head;
}
