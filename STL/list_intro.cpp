#include <iostream>
#include <list>
using namespace std;
void explainList()
{
    list<int> lst;
    lst.push_back(2);
    lst.emplace_back(4);
    lst.push_front(5);
    lst.emplace_front(6);
    //{6,5,2,4}
    cout<<lst.front()<<endl;
    cout<<lst.back()<<endl;
    lst.pop_front();
    lst.pop_back();
    for(auto it:lst)
        cout<<it<<" ";
}

int main()
{
    explainList();
}