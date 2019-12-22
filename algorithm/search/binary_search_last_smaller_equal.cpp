#include <iostream>

int binary_search_lse(int orig_array[], int size, int value) {
    if (size == 1)
        return orig_array[0] <= value ? 0 : -1;

    int low = 0, high = size - 1, mid = 0;
    while(low <= high) {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] > value) {
            high = mid - 1;
        } else {
            if (mid == size - 1 || orig_array[mid + 1] > value)
                return mid;
            else
                low = mid + 1;
        }
    }

    return -1;
}

int binary_search_lse2(int orig_array[], int size, int value) {
    if (size == 1)
        return orig_array[0] <= value ? 0 : -1;

    int low = 0, high = size - 1, mid = 0;
    while(low <= high) {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (high >= 0 && orig_array[high] <= value)
        return high;
    else
        return -1;
}


int main() {
    int test1[] = {2, 3, 4, 5, 6, 7, 9, 12, 12, 15, 15, 15, 16, 99, 100, 101};
    int value = 3;
    int pos = binary_search_lse2(test1, sizeof(test1)/sizeof(int), value);
    if (pos == -1) {
        std::cout << "can not find any element that is smaller than or equal to the value "
                  << value << std::endl;
    } else {
        std::cout << "find the element in pos " << pos << " is smaller than or equal to the value "
                  << value << " the element value is " << test1[pos] << std::endl;
    }

    int test2[] = {16};
    int value2 = 18;
    int pos2 = binary_search_lse2(test2, sizeof(test2)/sizeof(int), value2);
    if (pos2 == -1) {
        std::cout << "can not find any element that is smaller than or equal to the value "
                  << value2 << std::endl;
    } else {
        std::cout << "find the element in pos " << pos2 << " is smaller than or equal to the value "
                  << value2 << " the element value is " << test2[pos2] << std::endl;
    }

    return 0;
}