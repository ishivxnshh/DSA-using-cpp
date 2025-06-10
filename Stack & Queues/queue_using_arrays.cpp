#include <iostream>
using namespace std;

class Queue {
    int size;
    int *arr;
    int start, end;
public:
    Queue() {
        size = 1000;
        arr = new int[size];
        start = -1;
        end = -1;
    }
    void push(int x) {
        if (end == size - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (start == -1) start = 0;
        end++;
        arr[end] = x;
    }
    int pop() {
        if (start == -1 || start > end) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[start++];
        if (start > end) { // Reset queue if empty
            start = -1;
            end = -1;
        }
        return val;
    }
    int Front() {
        if (start == -1 || start > end) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int Size() {
        if (start == -1 || start > end) return 0;
        return end - start + 1;
    }
};

int main() {
    Queue q;
    q.push(6);
    q.push(3);
    q.push(7);
    cout << "Front of queue before deleting any element: " << q.Front() << endl;
    cout << "Size of queue before deleting any element: " << q.Size() << endl;
    cout << "The element deleted is: " << q.pop() << endl;
    cout << "Size of queue after deleting an element: " << q.Size() << endl;
    cout << "Front of queue after deleting an element: " << q.Front() << endl;
    return 0;
}
