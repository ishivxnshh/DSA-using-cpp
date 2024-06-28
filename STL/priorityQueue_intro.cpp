#include <iostream>
#include <queue>
using namespace std;
void explainPriorityQueue()
{
    priority_queue<int> pq;
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2}
    cout<<pq.top()<<endl; //10
    pq.pop(); //{8,5,2}
    cout<<pq.top()<<endl; //8

    //Minimum Heap(min. element on the top)
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5); //{5}
    pq1.push(2); //{2,5}
    pq1.push(8); //{2,5,8}
    pq1.push(9); //{2,5,8,9}
    pq1.emplace(9); //{2,5,8,9,10}
    cout<<pq1.top()<<endl; //2
}

int main()
{
    explainPriorityQueue();
}