#include <iostream>
#include <stdexcept>

class Dequeue
{
    int capacity;
    int *mem;
    int elements;
    int first;

public:
    Dequeue() : capacity(10),
                elements(0),
                first(0),
                mem(new int[capacity])
    {
    }
    ~Dequeue()
    {
        delete[] mem;
    }

    void dequeueElement()
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << mem[i] << " ";
        }
        std::cout<< std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    bool empty()
    {
        return (elements == 0);
    }
    bool isFull()
    {
        return (capacity == elements);
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
            capacity *= 2;
        }

        int insertion_location = (first + elements) % capacity;

        mem[insertion_location] = x;

        elements++;
    }

    void push_front(int x)
    {
        if (first == 0)
        {
            first = capacity - 1;
        }
        else
        {
            first = first - 1;
        }
        mem[first] = x;
    }

    void pop_front()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to delete from an empty Dequeue");
        }
        if (first == 0)
        {
            first= capacity-1;
        }
        else if (first == capacity-1){
            first = 0;
        }
        else
        {
            first ++;
        }
        
        
        // int front = mem[first];
        // first = (first + 1) % capacity;
        elements--;
        // return front;
    }

    int front()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty Dequeue");
        }

        return mem[first];
    }

    int back()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty Dequeue");
        }
        return mem[capacity-1];
    }

    void pop_back()
    {
        if (empty())
        {
            throw std::runtime_error("Underflow");
        }
        elements--;
    }

    Dequeue(const Dequeue &original) : capacity(original.capacity),
                                       elements(original.elements),
                                       mem(new int[capacity])
    {
        for (int i = 0; i < elements; i++)
        {
            mem[i] = original.mem[i];
        }
    }

    Dequeue &operator=(const Dequeue &original)
    {
        if (this != &original)
        {
            if (mem != nullptr)
                delete[] mem;
            capacity = original.capacity;
            elements = original.elements;
            mem = new int[capacity];
            for (int i = 0; i < elements; i++)
            {
                mem[i] = original.mem[i];
            }
        }
        return *this;
    }
};

int main()
{
    Dequeue q;
    for (int i = 0; i < 3; i++)
    {
        q.push_back(-i);
    }
    q.dequeueElement();
    for (int i = 0; i < 3; i++)
    {
        q.push_front(i+1);
    }
    q.dequeueElement();
    std::cout <<"back: "<< q.back() << std::endl;

    q.pop_front();

    std::cout <<"front: "<< q.front();
}
