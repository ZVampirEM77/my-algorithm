#include <iostream>
#include <time.h>

int partition(int orig_array[], int h, int t) {
    int mid = h + ((t - h) >> 1);
    int matter = orig_array[mid];
    orig_array[mid] = orig_array[t];

    int sl = h, i = h;

    while (i < t) {
        if (orig_array[i] < matter) {
            int tmp = orig_array[sl];
            orig_array[sl] = orig_array[i];
            orig_array[i] = tmp;
            sl++;
        }
        i++;
    }

    orig_array[t] = orig_array[sl];
    orig_array[sl] = matter;

    return sl;
}

void quick_sort(int orig_array[], int h, int t) {
    if (h >= t)
        return;
    int pivot = partition(orig_array, h, t);
    quick_sort(orig_array, h, pivot - 1);
    quick_sort(orig_array, pivot + 1, t);
}

int main() {
    int test1[] = {4, 5, 6, 7, 1, 2, 3, 4};
    time_t start = time(NULL);
    quick_sort(test1, 0, sizeof(test1)/sizeof(int) - 1);
    time_t end = time(NULL);

    std::cout << "time1 = " << end - start << std::endl;

    for (auto iter : test1) {
        std::cout << iter << std::endl;
    }

    std::cout << "========================" << std::endl;

    int test2[] = {1, 2, 3, 4, 5, 9, 99, 100};
    start = time(NULL);
    quick_sort(test2, 0, sizeof(test2)/sizeof(int) - 1);
    end = time(NULL);

    std::cout << "time2 = " << end - start << std::endl;

    for (auto iter : test2) {
        std::cout << iter << std::endl;
    }

    return 0;
}