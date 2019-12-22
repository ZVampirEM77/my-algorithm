#include <iostream>

int binary_search_last_equal(int orig_array[], int size, int value) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (high >= 0 && orig_array[high] == value)
        return high;
    else
        return -1;
}

int binary_search_last_equal2(int orig_array[], int size, int value) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] > value) {
            high = mid - 1;
        } else if (orig_array[mid] < value) {
            low = mid + 1;
        } else {
            if (mid == size - 1 || orig_array[mid + 1] > value)
                return mid;
            else
                low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int test1[] = {2, 3, 4, 5, 6, 7, 9, 12, 12, 15, 15, 15, 16, 99, 100, 101};
    int value = 15;
    int pos = binary_search_last_equal2(test1, sizeof(test1)/sizeof(int), value);

    if (pos == -1) {
        std::cout << "not find value " << value << std::endl;
    } else {
        std::cout << "find the last element which is equal to valule " << value
                  << " the pos is " << pos << std::endl;
    }

    return 0;
}