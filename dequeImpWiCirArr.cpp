#include <iostream>

class Deque
{
    int first, last, capacity;
    int *mem;

public:
    Deque() : capacity(10), first(-1), last(0), mem(new int[capacity])
    {
    }

    void dequeElement(){
        for (size_t i = 0; i < capacity; i++)
        {
            std::cout<<mem[i]<<" ";
        }
    }

    ~Deque()
    {
        if (mem != nullptr)
        {
            delete[] mem;
        }
    }
    bool isFull(){
        return (first == 0 && last == capacity-1 || first == last + 1);
    }

    bool isEmpty(){
        return (first == -1);
    }

    void insertRear(int x){
        if (isFull())
        {
           throw std::runtime_error("Overflow");
        }
        if (first == -1)
        {
            first = 0;
            last = 0;
        }
        else if(last == capacity-1){
            last = 0;
        }
        else
        {
            last += 1;
        }
        mem[last] = x;   
    }

    int getRear(){
        if (isEmpty() || last<0)
        {
            throw std::runtime_error("Underflow");
        }
        return mem[last];  
    }

    void deleteRear(){ 
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        if (first == last)
        {
            first = -1;
            last = -1;
        }
        else if(last == 0){
            last = capacity-1;
        }
        else
        {
            last -= 1;
        }  
    }

    void insertFront(int x){
        if (isFull())
        {
            throw std::runtime_error("Overflow");
        }
        if (first == -1)
        {
            first = 0;
            last = 0;
        }
        else if(first == 0){
            first = capacity-1;
        }
        else
        {
            first = first -1;
        }
        mem[first] = x;   
        
    }

    int getFront(){
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        return mem[first];  
    }

    void deleteFront(){
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        if (first == last)
        {
            first = -1;
            last = -1;
        }
        else if(first == capacity-1){
            first = 0;
        }
        else
        {
            first = first + 1;
        }   
    }
};

int main()
{
    Deque dq;
    // for (int i = 0; i < 3; i++)
    // {
    //     dq.insertRear(-i);
    // }
    
    for (int i = 0; i < 3; i++)
    {
        dq.insertFront(i);
    }
    
    dq.dequeElement();
    // std::cout<<std::endl;
    // std::cout<<dq.getRear()<<std::endl;
    // dq.deleteRear();
    // std::cout<<dq.getFront()<<std::endl;
    // dq.deleteFront();
    return 0;
}