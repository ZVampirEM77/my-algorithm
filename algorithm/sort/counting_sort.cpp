#include <iostream>


// counting_sort is suitable for:
// 1. the range of sorting number is not larger than number counts too much
// 2. the number needing to be sorted must be nonnegative integer 
int *counting_sort(int orig_array[], int size) {
    if (size <= 1) return orig_array;

    int max_ele = orig_array[0];

    // make sure the range of the numbers needing to be sorted
    for (int i = 1; i < size; i++) {
        if (orig_array[i] > max_ele) {
            max_ele = orig_array[i];
        }
    }

    // create count array
    int* count_array = new int[max_ele + 1]();

    // fill the count array
    for (int i = 0; i < size; i++) {
        count_array[orig_array[i]]++;
    }

    for (int i = 1; i < max_ele + 1; i++) {
        count_array[i] = count_array[i] +
                        count_array[i - 1];
    }

    int *sorted_array = new int[size]();
    for (int i = size - 1; i >= 0; i--) {
        sorted_array[(count_array[orig_array[i]]--) - 1] = orig_array[i];
    }

    return sorted_array;
}

int main() {
    int test1[] = {2, 3, 4, 0, 1, 3, 5, 6, 1, 2, 0, 5, 2};
    int test1_size = sizeof(test1)/sizeof(int);
    int *sorted_res = counting_sort(test1, test1_size);
    for (int i = 0; i < test1_size; i++) {
        std::cout << sorted_res[i] << std::endl;
    }

    return 0;
}