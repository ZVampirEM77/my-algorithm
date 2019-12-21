#include <iostream>

int bsearch(int array[], int size, int value) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if (array[mid] >= value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low < size && array[low] == value) return low;
    else return -1;
}

int bsearch2(int array[], int size, int value) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (array[mid] > value) {
            high = mid - 1;
        } else if (array[mid] < value) {
            low = mid + 1;
        } else {
            if ((mid == 0) || (array[mid - 1] != value)) return mid;
            else high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int test1[] = {1, 2, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    int pos1 = bsearch(test1, sizeof(test1)/sizeof(int), 5);
    std::cout << "the first pos of 5 is " << pos1 << std::endl;

    int pos2 = bsearch2(test1, sizeof(test1)/sizeof(int), 3);
    std::cout << "the first pos of 3 is " << pos2 << std::endl;

    return 1;
}