#include <iostream>

int binary_search_fle(int orig_array[], int size, int value) {
    if (size == 1) {
        return orig_array[0] >= value ? 0 : -1;
    }

    int low = 0, high = size - 1, mid = 0;

    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] >= value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low < size && orig_array[low] >= value) {
        return low;
    } else {
        return -1;
    }
    
}

int binary_search_fle2(int orig_array[], int size, int value) {
    if (size == 1) {
        return orig_array[0] >= value ? 0 : -1;
    }

    int low = 0, high = size - 1, mid = 0;

    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] < value) {
            low = mid + 1;
        } else {
            if (mid == 0 || orig_array[mid - 1] < value)
                return mid;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int test1[] = {2, 3, 4, 5, 6, 7, 9, 12, 12, 15, 15, 15, 16, 99, 100, 101};
    int value = 120;
    int pos = binary_search_fle2(test1, sizeof(test1)/sizeof(int), value);
    if (pos == -1) {
        std::cout << "can not find any element that is larger than or equal to the value "
                  << value << std::endl;
    } else {
        std::cout << "find the element in pos " << pos << " is larger than or equal to the value "
                  << value << " the element value is " << test1[pos] << std::endl;
    }

    return 0;
}