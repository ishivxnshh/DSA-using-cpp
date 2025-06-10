#include <iostream>
using namespace std;

class Queue
{
    int currSize;
    int size;
    int *arr;
    int start, end;

public:
    Queue()
    {
        size = 1000;
        arr = new int[size];
        currSize = 0;
        start = -1;
        end = -1;
    }
    void push(int x)
    {
        if (currSize == size)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (currSize == 0)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % size;
        arr[end] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int result = arr[start];
        if (currSize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % size;
        }
        currSize--;
        return result;
    }

    int front()
    {
        if (currSize == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start];
    }

    int getSize()
    {
        return currSize;
    }
};

int main()
{
    Queue q;
    q.push(6);
    q.push(3);
    q.push(7);
    cout << "Front of queue before deleting any element: " << q.front() << endl;
    cout << "Size of queue before deleting any element: " << q.getSize() << endl;
    cout << "The element deleted is: " << q.pop() << endl;
    cout << "Size of queue after deleting an element: " << q.getSize() << endl;
    cout << "Front of queue after deleting an element: " << q.front() << endl;
    return 0;
}