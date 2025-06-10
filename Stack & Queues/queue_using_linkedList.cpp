#include <iostream>
using namespace std;

struct queueNode
{
    int data;
    queueNode *next;
    int size;
    queueNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue
{
    int size = 0;
    queueNode *start = nullptr, *end = nullptr;
    bool Empty()
    {
        return start == nullptr;
    }
    int Peek()
    {
        if (Empty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
            return start->data;
    }
    void Enqueue(int value)
    {
        queueNode *Temp = new queueNode(value);
        if (start == nullptr)
        {
            start = end = Temp;
        }
        else
        {
            end->next = Temp;
            end = Temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++;
    }
    void Dequeue()
    {
        if (Empty())
            cout << "Queue is Empty" << endl;
        else
        {
            cout << start->data << " Removed From Queue" << endl;
            queueNode *temp = start;
            start = start->next;
            delete temp;
            size--;
        }
    }
};
int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}