#include <iostream>
#include <stdexcept>

class Queue
{
    int capacity;
    int *mem;
    int elements;
    int first;

public:
    // write the constructor for Queue which initializes:
    // capacity to 10
    // mem with a new array
    // elements with 0
    // first with 0
    Queue() : capacity(10),
              elements(0),
              first(0),
              mem(new int[capacity])
    {
    }

    // write a destructor for Queue
    ~Queue()
    {
        delete[] mem;
    }

    bool empty()
    {
        return (elements == 0);
    }
    bool isFull()
    {
        return (capacity == elements);
    }
    void push(int x)
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
            capacity *= 2;
        }

        int insertion_location = (first + elements) % capacity;

        mem[insertion_location] = x;

        elements++;
    }

    int pop()
    {
        // warning: unsafe, make safe
        if (empty())
        {
            throw std::runtime_error("Trying to delete from an empty queue");
        }
        int front = mem[first];
        first = (first + 1) % capacity;
        elements--;
        return front;
    }

    int front()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty queue");
        }

        return mem[first];
    }

    int last()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty queue");
        }
        return mem[elements];
    }

    Queue(const Queue &original) : capacity(original.capacity),
                                   elements(original.elements),
                                   mem(new int[capacity])
    {
        for (int i = 0; i < elements; i++)
        {
            mem[i] = original.mem[i];
        }
    }

    Queue &operator=(const Queue &original)
    {
        if (this != &original)
        { // guard against self assignment
            if (mem != nullptr)
                delete[] mem;             // if mem is allocated, delete it
            capacity = original.capacity; // copy fields from the original
            elements = original.elements; // copy fields from the original
            mem = new int[capacity];      // allocate a new array
            for (int i = 0; i < elements; i++)
            { // copy mem element by element from original
                mem[i] = original.mem[i];
            }
        }
        return *this; // always return a reference
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 3; i++)
    {
        q.push(-i);
    }

    // q.pop();

    std::cout << q.front();
}
