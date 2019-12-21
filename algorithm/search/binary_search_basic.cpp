#include <iostream>

bool binary_search(int array[], int head, int tail, int value) {
    if (head > tail) {
        return false;
    }

    int mid = head + ((tail - head) >> 1);
    if (array[mid] == value)
        return true;
    else if (array[mid] > value) {
        return binary_search(array, head, mid - 1, value);
    } else {
        return binary_search(array, mid + 1, tail, value);
    }
}

int main() {
    int test[] = {2, 3, 4, 5, 6, 7, 9, 11, 77, 99, 100, 101};
    int value = 0;

    for (auto iter : test) {
        value = iter;
        if (binary_search(test, 0, sizeof(test)/sizeof(int) - 1, value)) {
            std::cout << "find value " << value << std::endl;
        } else {
            std::cout << "can not find value " << value << std::endl;
        }
    }

    value = 1;
    if (binary_search(test, 0, sizeof(test)/sizeof(int) - 1, value)) {
        std::cout << "find value " << value << std::endl;
    } else {
        std::cout << "can not find value " << value << std::endl;
    }

    return 0;
}