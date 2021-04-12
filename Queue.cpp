#include "Queue.h"
Queue::Queue()
{
    Head = nullptr;
    Tail = nullptr;
}
Queue::Queue(Queue &stuff) {
    Head = nullptr;
    Tail = nullptr;
    if (stuff.Head == nullptr)
    {
        Head = Tail = nullptr;
        return;
    }
    thing *temp = stuff.Head;
    while (temp != nullptr)
    {
        push(temp->num);
        temp = temp->Next;
    }
}
Queue::Queue(Queue&& other)noexcept
{
    if (other.Head == nullptr)
    {
        Head = Tail = nullptr;
        return;
    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = other.Tail = nullptr;
}
Queue::~Queue() {
    thing *temp = Head;
    while (temp != nullptr)
    {
        temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void Queue::push(const int &num) {
    auto *temp = new thing;
    temp->Next = nullptr;
    temp->num = num;
    if(Head != nullptr)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        temp->Prev = nullptr;
        Head = Tail = temp;
    }
}


int Queue::peek() {
    thing *temp = Head;
    return temp->num;
}


int Queue::GetSize() {
    if (Head == nullptr) return 0;
    thing *temp = Head;
    int size = 0;
    while (temp != nullptr)
    {
        size += 1;
        temp = temp->Next;
    }
    return size;
}


int Queue::pop() {
    int rst;
    if ((Head != nullptr) && (Head->Next))
    {
        rst = Head->num;
        thing *temp = Head;
        Head = Head->Next;
        Head->Prev = nullptr;
        delete temp;
        return rst;
    }
    else if ((Head != nullptr) && (Head == Tail))
    {
        rst = Head->num;
        Head->Next = nullptr;
        Head = nullptr;
        delete Head;
        return rst;
    }
}
Queue &Queue::operator=(const Queue &other)noexcept {
    Head = nullptr;
    Tail = nullptr;
    if (other.Head == nullptr)
    {
        Head = Tail = nullptr;
        return *this;
    }
    thing *temp = other.Head;
    while (temp != nullptr)
    {
        push(temp->num);
        temp = temp->Next;
    }
    return *this;
}
Queue &Queue::operator=(Queue &&other)noexcept {
    if (this == &other || other.Head == nullptr) {
        return *this;
    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = other.Tail = nullptr;
    return *this;
}

