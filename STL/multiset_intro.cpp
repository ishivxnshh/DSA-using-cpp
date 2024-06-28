#include <iostream>
#include <set>
using namespace std;
void explainMultiSet() //(sorted but not unique)
{
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    //ms.erase(1); //all 1's erased

    int cnt = ms.count(1);

    ms.erase(ms.find(1)); //only a single 1 erased
    ms.erase(ms.find(1), ms.end());

    for(auto it:ms)
        cout<<it<<" ";
}

int main()
{
    explainMultiSet();
}