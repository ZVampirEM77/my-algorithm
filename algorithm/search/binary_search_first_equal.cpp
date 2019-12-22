#include <iostream>

// return the index if find the value in array
// return -1 if not find
int binary_search_first_equal(int orig_array[], int size, int value)
{
    if (size == 1) {
        return (orig_array[0] == value) ? 0 : -1;
    }

    int low = 0, high = size -1, mid = 0;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] >= value) {
            high = mid - 1;
        } else if (orig_array[mid] < value) {
            low = mid + 1;
        }
    }

    if (low < size && orig_array[low] == value) {
        return low;
    } else
        return -1;
}

int binary_search_first_equal2(int orig_array[], int size, int value)
{
    if (size == 1) {
        return (orig_array[0] == value) ? 0 : -1;
    }

    int low = 0, high = size -1, mid = 0;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (orig_array[mid] > value) {
            high = mid - 1;
        } else if (orig_array[mid] < value) {
            low = mid + 1;
        } else {
            if (mid == 0 || orig_array[mid - 1] < value )
                return mid;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int test1[] = {2, 3, 4, 5, 6, 9, 11, 11, 11, 22, 55, 100, 101};
    int value = 102;
    int pos = binary_search_first_equal2(test1, sizeof(test1)/sizeof(int), value);
    if (pos == -1) {
        std::cout << "not find value " << value << std::endl;
    } else {
        std::cout << "the first element that is equal to value " << value
                  << " is in pos " <<  pos << std::endl;
    }

    return 0;
}