#ifndef LABWORK5_QUEUE_H
#define LABWORK5_QUEUE_H
#include <iostream>
using namespace std;


struct thing {
    int num;
    thing *Prev;
    thing *Next;
};


class Queue {
    thing *Head;
    thing *Tail;
public:
    Queue();
    Queue(Queue &stuff);
    Queue(Queue&& other)noexcept;
    ~Queue();
    int GetSize();
    void push(const int &num);
    int pop();
    int peek();
    Queue &operator=(const Queue &other)noexcept;
    Queue &operator=(Queue &&other)noexcept;
    friend ostream &operator<<(ostream &stream, const Queue &garbage)
    {
        if (garbage.Head == nullptr) return stream << "Your queue's empty \n";
        thing *temp = garbage.Head;
        while (temp != nullptr)
        {
            stream << temp->num<< " ";
            temp = temp->Next;
        }
        cout << endl;
        return stream;
    }
};
#endif
