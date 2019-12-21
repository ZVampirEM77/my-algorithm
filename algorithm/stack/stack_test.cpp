#include <iostream>
#include <ArrayStack.h>

int main()
{
    ArrayStack stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(7);
    stack.push(77);

    int res1 = stack.pop();
    std::cout << "res1 = " << res1 << std::endl;

    int res2 = stack.pop();
    std::cout << "res2 = " << res2 << std::endl;

    stack.push(88);
    stack.push(99);

    int res3 = stack.pop();
    std::cout << "res3 = " << res3 << std::endl;

    int res4 = stack.pop();
    std::cout << "res4 = " << res4 << std::endl;

    int res5 = stack.pop();
    std::cout << "res5 = " << res5 << std::endl;

    return 0;
}