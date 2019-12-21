#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <cstring>

class ArrayStack
{
private:
    int *internal_array;  // the pointer to the internal array
    int count; // the count of element in stack
    int size; // the size of the stack

public:
    ArrayStack(int stack_size)
    {
        internal_array = new int [stack_size];
        memset(internal_array, 0, 4 * stack_size);
        count = 0;
        size = stack_size;
    }

    ~ArrayStack() {delete [] internal_array;}

    bool push (int value)
    {
        if (count == size)
            return false;

        *(internal_array + count) = value;
        count += 1;
        return true;
    }

    int pop()
    {
        if (!count)
            return -1;

        int res_value = *(internal_array + (count - 1));
        *(internal_array + (count - 1)) = 0;
        count -= 1;
        return res_value;
    }
};

#endif