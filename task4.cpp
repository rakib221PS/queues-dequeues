#include <iostream>
#include <stdexcept>
#include "Deque.h"
#include <fstream>

int main()
{
    Deque d;
    std::string frontOrBack;
    int number;
    std::ifstream fileOutPut;
    fileOutPut.open("fOrB.txt");
    if (fileOutPut.good())
    {
        while (fileOutPut >> frontOrBack >> number)
        {
            if (frontOrBack == "front")
            {
                d.push_front(number);
            }
            else
            {
                d.push_back(number);
            }
        }
    }
    else
    {
        throw std::runtime_error("Trying to access from an empty file");
    }

    for (int i = 0; i < 7; i++)
    {
        std::cout << d.mem[i] << " ";
    }

    return 0;
}