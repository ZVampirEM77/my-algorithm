#include <iostream>

void select_sort(int orig_array[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size; i++) {
        int min = orig_array[i];
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (orig_array[j] < min) {
                min = orig_array[j];
                min_index = j;
            }
        }
        
        orig_array[min_index] = orig_array[i];
        orig_array[i] = min;
    }
}

int main() {
 //   int test1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
 //   select_sort(test1, sizeof(test1)/sizeof(int));
 //   for (auto i : test1) {
 //       std::cout << i << std::endl;
 //   }

    int test2[] = {4, 5, 6, 9, 4, 99, 100, 99, 98};
    select_sort(test2, sizeof(test2)/sizeof(int));
    for (auto i : test2) {
        std::cout << i << std::endl;
    }

    std::cout << "==================================" << std::endl;

    int test3[] = {98};
    select_sort(test3, sizeof(test3)/sizeof(int));
    for (auto i : test3) {
        std::cout << i << std::endl;
    }

    return 0;
}