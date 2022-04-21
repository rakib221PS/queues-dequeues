#include <iostream>

class Deque
{
public:
    int capacity, elements;
    int *mem;

public:
    Deque() : capacity(10), elements(-1), mem(new int[capacity])
    {
    }

    void dequeElement()
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << mem[i] << " ";
        }
    }

    ~Deque()
    {
        delete[] mem;
    }
    bool isFull()
    {
        return (elements == capacity);
    }

    bool isEmpty()
    {
        return (elements == -1);
    }

    void pushFront(int x)
    {
        elements++;
        if (isFull())
        {
            // throw std::runtime_error("Overflow");
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            capacity *= 2;
            delete[] mem;
            mem = newMem;
        }

        // if (isEmpty())
        // {
        //     elements++;
        //     mem[elements] = x;
        //     // std::cout<<mem[0] << " ";
        // }
        if (elements >= 0)
        {
            int newelements = elements;
            int el = elements;
            for (int i = newelements; i > 0; i--)
            {
                el--;
                mem[i] = mem[el];
                // std::cout<<mem[i] << " ";
            }
            mem[0] = x;
            // std::cout<<mem[0];
        }
    }

    void popFront()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        if (elements == 0)
        {
            elements--;
        }
        else
        {
            for (int i = 0; i < elements; i++)
            {
                mem[i] = mem[i + 1];
                // std::cout<<mem[i]<<" ";
            }
            elements--;
        }
    }

    void pushBack(int x)
    {
        elements++;
        if (isFull())
        {
            // throw std::runtime_error("Overflow");
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            capacity *= 2;
            delete[] mem;
            mem = newMem;
        }
        // if (isEmpty())
        // {
        //     mem[elements] = x;
        // }
        if (elements >= 0)
        {
            mem[elements] = x;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        elements--;
    }
    int font()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to read from empty memory");
        }
        return mem[0];
    }
    int back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to read from empty memory");
        }
        return mem[elements];
    }
};

int main()
{
    Deque dq;
    for (int i = 0; i < 50; i++)
    {
        dq.pushFront(-i);
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << dq.mem[i] << std::endl;
    // }
    for (int i = 0; i < 50; i++)
    {
        dq.pushBack(-i);
    }

    dq.popFront();
    // std::cout << std::endl;
    // dq.pushBack(45);
    // std::cout<<dq.mem[0];
    dq.popBack();
    for (int i = 0; i < 100; i++)
    {
        std::cout << dq.mem[i] << " ";
    }
    std::cout << std::endl;
    std::cout << dq.font() << std::endl;
    std::cout << dq.back() << std::endl;
    return 0;
}