#include <iostream>
#include <time.h>
#include <cstdlib>
#include "quick_sort.h"

// let's assume the range of sorting numbers are 
// nonnegative integer which are all smaller than
// 100
void bucket_sort(int orig_array[], int size) {
    int min = orig_array[0], max = orig_array[0];

    for (int i = 0; i < size; i++) {
        if (min > orig_array[i]) {
            min = orig_array[i];
        }

        if (max < orig_array[i]) {
            max = orig_array[i];
        }
    }

    int bucket_count = (max - min)/10 + 2;

    int ** bucket = new int*[bucket_count];
    for (int i = 0; i < bucket_count; i++) {
        bucket[i] = new int[size]();
    }

    int* bucket_internal_count = new int[bucket_count]();

    for (int i = 0; i < size; i++) {
        int bucket_index = orig_array[i] / 10 - min / 10;
        bucket[bucket_index][bucket_internal_count[bucket_index]++] = orig_array[i];
    }

    for (int i = 0; i < bucket_count; i++) {
        quick_sort(bucket[i], 0, bucket_internal_count[i] - 1);
    }

    int *tmp_array = new int[size]();
    int tmp_index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < bucket_internal_count[i]; j++) {
            tmp_array[tmp_index++] = bucket[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        orig_array[i] = tmp_array[i];
    }
}

void generate_random_num(int orig_array[], int size) {
    srand((int)time(0));
    for (int i = 0; i < size; i++) {
        orig_array[i] = rand()%100;
    }
}


int main() {
    int test1[50];
    generate_random_num(test1, sizeof(test1)/sizeof(int));
    for(auto iter : test1) {
        std::cout << iter << std::endl;
    }

    std::cout << "=========================================" << std::endl;

    bucket_sort(test1, sizeof(test1)/sizeof(int));
    for(auto iter : test1) {
        std::cout << iter << std::endl;
    }
    return 0;
}