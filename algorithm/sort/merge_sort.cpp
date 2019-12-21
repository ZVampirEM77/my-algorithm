#include <iostream>

void merge(int array1[], int size1, int array2[], int size2, int *merge_array) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            merge_array[k] = array1[i];
            i++;
        } else {
            merge_array[k] = array2[j];
            j++;
        }
        k++;
    }

    if (i == size1) {
        for (; j < size2; j++, k++) {
            merge_array[k] = array2[j];
        }
    } else {
        for (; i < size1; i++, k++) {
            merge_array[k] = array1[i];
        }
    }
}

// t is the index of the last element;
int * merge_sort(int orig_array[], int h, int t) {
    if (h > t)
        return NULL;

    int *merge_array = new int [t - h + 1];

    if (h == t) {
        merge_array[0] = orig_array[h];
    } else {
        int mid = (h + t) / 2;
        int * left_array = merge_sort(orig_array, h, mid);
        int * right_array = merge_sort(orig_array, mid + 1, t);
        merge(left_array, mid - h + 1, right_array, t - mid, merge_array);
        delete [] left_array;
        delete [] right_array;
    }

    return merge_array;
}


int main()
{
    int test1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int test1_size = sizeof(test1) / sizeof(int);
    int *res1 = merge_sort(test1, 0, test1_size - 1);

    for (int i = 0; i < test1_size; i++) {
        std::cout << res1[i] << std::endl;
    }

    delete [] res1;

    std::cout << "===============================" << std::endl;

    int test2[] = {3, 5, 7, 99, 5, 77, 100, 1000};
    int test2_size = sizeof(test2) / sizeof(int);
    int *res2 = merge_sort(test2, 0, test2_size - 1);

    for (int i = 0; i < test2_size; i++) {
        std::cout << res2[i] << std::endl;
    }

    delete [] res2;

    std::cout << "===============================" << std::endl;

    int test3[] = {3};
    int test3_size = sizeof(test3) / sizeof(int);
    int *res3 = merge_sort(test3, 0, test3_size - 1);

    for (int i = 0; i < test3_size; i++) {
        std::cout << res3[i] << std::endl;
    }

    delete [] res3;

    std::cout << "===============================" << std::endl;

    int test4[] = {1, 2};
    int test4_size = sizeof(test4) / sizeof(int);
    int *res4 = merge_sort(test4, test4_size - 1, 0);

    if (res4) {
        for (int i = 0; i < test4_size; i++) {
            std::cout << res4[i] << std::endl;
        }
    } else {
        std::cout << "res4 is NULL" << std::endl;
    }
    delete [] res4;

    std::cout << "===============================" << std::endl;

    return 0;
}


