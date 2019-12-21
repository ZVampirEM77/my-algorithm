#include <iostream>
#include <cassert>

#define GET_GOLD(x, y) (x / y) % 10

void counting_sort(int orig_array[], int size, int bit) {
    if (size <= 1) return;

    int max_ele = GET_GOLD(orig_array[0], bit);

    // make sure the range of the numbers needing to be sorted
    int ele = 0;
    for (int i = 1; i < size; i++) {
        ele = GET_GOLD(orig_array[i], bit);
        if (ele > max_ele) {
            max_ele = ele;
        }
    }

    // create count array
    int* count_array = new int[max_ele + 1]();

    // fill the count array
    for (int i = 0; i < size; i++) {
        count_array[GET_GOLD(orig_array[i], bit)]++;
    }

    for (int i = 1; i < max_ele + 1; i++) {
        count_array[i] = count_array[i] +
                        count_array[i - 1];
    }

    int *sorted_array = new int[size]();
    for (int i = size - 1; i >= 0; i--) {
        sorted_array[(count_array[GET_GOLD(orig_array[i], bit)]--) - 1] = orig_array[i];
    }

    for (int i = 0; i < size; i++) {
        orig_array[i] = sorted_array[i];
    }

    return;
}

int get_length(int x) {
    assert(x >= 0);
    int length = 1;

    while (x >= 10) {
        x /= 10;
        length += 1;
    }

    return length;
}

void radix_sort(int orig_array[], int size) {
    if (size <= 1) return;

    int max_len = get_length(orig_array[0]);
    for (int i = 1; i < size; i++) {
        int ele_len = get_length(orig_array[i]);
        if (max_len < ele_len)
            max_len = ele_len;
    }

    for (int i = 0, bit = 1; i < max_len; i++, bit *= 10) {
        counting_sort(orig_array, size, bit);
    }
}

int main() {
    int test1[] = {155245, 92968, 1851656, 5896, 187, 200, 92590738, 364935961};
    radix_sort(test1, sizeof(test1)/sizeof(int));
    for (auto iter : test1) {
        std::cout << iter << std::endl;
    }
    return 0;
}