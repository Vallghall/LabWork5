#include <iostream>
#include "Queue.h"
int main() {
    Queue list;
    for (int i = 0; i <= 4; i++)
    {
        list.push(i);
    }
    cout << "The size of the queue is " <<  list.GetSize() << endl;
    cout << "The top element in queue is " << list.peek() << endl;
    cout << "The first list is:\t" << list;
    Queue fist = list;
    cout << "The copied list is:\t" << fist;
    for (int i = 0; i <= 4; i++)
    {
        cout << "The element " << list.pop() << " is out\n";
    }
    list.push(3);
    list.push(7);
    list.push(11);
    cout << list;
    Queue mist = move(list);
    cout << "THe first list after removal: "<< list;
    cout << "The moved list is:\t" << mist;
}
