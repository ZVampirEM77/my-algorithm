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

template <class T>
T* CreateCycledLinkedList(int n) {
    if (!n) {
        return nullptr;
    }

    srand((unsigned int)time(NULL));
    T * head = new T(rand());

    if (n == 1) {
        return head;
    }

    T * cur_node = head;
    int rand_index = rand() % (n - 1);
    T * rand_node = nullptr;

    for (int i = 1; i < n; i++) {
        cur_node->next = new T(rand());
        cur_node = cur_node->next;
        if (i == rand_index) {
            rand_node = cur_node;
        }
    }

    if (rand_node == nullptr) {
        cur_node->next = head;
    } else {
        cur_node->next = rand_node;
    }

    return head;
}
