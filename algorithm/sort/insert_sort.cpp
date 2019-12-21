#include <iostream>

void insert_sort(int *orig_array, int size) {
    if (size <= 1) return;

    int key = 0;

    for (int i = 1; i < size; i++) {
        key = *(orig_array + i);

        int j = i - 1;
        for (; j >= 0; j--) {
            if (*(orig_array + j) > key) {
                *(orig_array + j + 1) = *(orig_array + j);
                continue;
            }

            break;
        }

        *(orig_array + j + 1) = key;
    }
}

int main() {
 //   int test1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
 //   insert_sort(test1, sizeof(test1) / sizeof(int));

//    for (auto i : test1) {
//        std::cout << i << std::endl;
//    }

 //   int test2[] = {4, 5, 9, 7, 4, 2, 1, 99, 10000};
 //   insert_sort(test2, sizeof(test2) / sizeof(int));
 //   for (auto i : test2) {
 //       std::cout << i << std::endl;
 //   }

   int test3[] = {4};
   insert_sort(test3, sizeof(test3) / sizeof(int));
    for (auto i : test3) {
        std::cout << i << std::endl;
   }

    return 0;
}