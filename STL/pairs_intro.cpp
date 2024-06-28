#include <iostream>
#include <utility>
using namespace std;

void explainPair()
{
    pair<int, int> p1 = {1, 2};
    cout<<p1.first<<' '<<p1.second;
    cout<<endl;
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout<<p2.first<<' '<<p2.second.second<<' '<<p2.second.first;
    cout<<endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout<<arr[1].second;   
}

int main()
{
    explainPair();
}    