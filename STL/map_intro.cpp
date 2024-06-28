#include <iostream>
#include <map>
using namespace std;
void explainMap()
{
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;  
    map<pair<int, int>, int> mpp2; 

    mpp[1] = 2;
    mpp.emplace(3,1);
    mpp.insert({2,4});
    mpp2[{2,3}]=10;

    for(auto it:mpp)
        cout<<it.first<<" "<<it.second<<endl; 

    cout<<mpp[1]<<endl;
    cout<<mpp[5]<<endl;

    auto it = mpp.find(3);
    cout<<(*it).second<<endl;
    //cout<<it->second<<endl;
    
    auto it1 = mpp.find(5); //if it is not there it points to mpp.end()

    auto it2 = mpp.lower_bound(2);
    auto it3 = mpp.lower_bound(3);

int main()
{
    explainMap();
}