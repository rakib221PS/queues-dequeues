#include <iostream>
#include <stdexcept>
#include "Deque.h"

int main()
{
    Deque d;
    for (int i = 0; i < 2; i++)
    {
        d.push_front(-i);
    }

    for (int i = 0; i < 2; i++)
    {
        std::cout << d.mem[i] << " ";
    }

    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        d.push_front(i);
    }
    for (int i = 0; i < 4; i++)
    {
        std::cout << d.mem[i] << " ";
    }

    return 0;
}