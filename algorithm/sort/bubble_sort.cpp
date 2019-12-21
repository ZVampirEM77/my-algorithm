#include <iostream>

void bubble_sort(int *orig_array, int array_size) {
    bool change = false;

    if (orig_array == NULL) {
        return;
    }

    for (int i = array_size - 1; i >= 0; i--) {

        std::cout << "in sort process" << std::endl;

        for (int j = 0; j < i; j++) {
            int tmp = 0;
            if (*(orig_array + j) > *(orig_array + j + 1)) {
                tmp = *(orig_array + j);
                *(orig_array + j) = *(orig_array + j + 1);
                *(orig_array + j + 1) = tmp;

                if (!change)
                    change = true;
            }
        }

        if (!change)
            break;

        change = false;
    }
}

int main() {
//    int a[] = {6, 7, 1, 2, 3, 4, 77, 34, 99};
    int *a = NULL;
    bubble_sort(a, sizeof(a)/sizeof(int));

    if (a == NULL) {
        std::cout << "a is NULL" << std::endl;
    } else {
        std::cout << "a is not NULL" << std::endl;
    }
 //   for (auto e : a) {
 //       std::cout << e << std::endl;
 //   }

    return 0;
}