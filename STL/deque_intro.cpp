#include <iostream>
#include <deque>
using namespace std;
void explainDeque()
{
    deque<int> dq;
    dq.push_back(2);
    dq.emplace_back(4);
    dq.push_front(5);
    dq.emplace_front(6);
    //{6,5,2,4}
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_front();
    dq.pop_back();
    for(auto it:dq)
        cout<<it<<" ";
}

int main()
{
    explainDeque();
}