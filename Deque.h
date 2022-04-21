#ifndef Deque_H
#define Deque_H
class Deque
{
public:
    int capacity, first, last, elements;
    int *mem;

public:
    Deque() : capacity(7), first(-1), last(0), elements(0), mem(new int[capacity])
    {
    }
    ~Deque()
    {
        if (mem != nullptr)
        {
            delete[] mem;
        }
    }
    bool isFull()
    {
        return (first == 0 && last == capacity - 1 || first == last + 1);
    }

    bool isEmpty()
    {
        return (first == -1);
    }
    void push_back(int x)
    {
        if (isFull())
        {
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            delete[] mem;
            mem = newMem;
            capacity = capacity * 2;
        }
        if (isEmpty())
        {
            first = 0;
            last = 0;
        }
        else if (last == capacity - 1)
        {
            last = 0;
        }
        else
        {
            last = last + 1;
        }
        mem[last] = x;
    }

    void push_front(int x)
    {
        if (isFull())
        {
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            delete[] mem;
            mem = newMem;
            capacity = capacity * 2;
        }
        if (isEmpty())
        {
            first = 0;
            last = 0;
        }
        else if (first == 0)
        {
            first = capacity - 1;
        }
        else
        {
            first--;
        }

        mem[first] = x;
    }

    void pop_back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        if (last == first)
        {
            last = -1;
            first = -1;
        }
        else if (last == 0)
        {
            last = capacity - 1;
        }
        else
        {
            last--;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        if (first == capacity - 1)
        {
            first = 0;
        }
        else if (first == last)
        {
            first = -1;
            last = -1;
        }
        else
        {
            first = first + 1;
        }
    }

    int front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Memory is not allocated");
        }
        return mem[first];
    }

    int back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Memory is not allocated");
        }
        return mem[last];
    }
};

#endif