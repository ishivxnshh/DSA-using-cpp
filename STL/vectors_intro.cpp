#include <iostream>
#include <vector>
using namespace std;

void explainVector()
{
    vector<int> v;
    v.push_back(1);
    cout<<"capacity: "<<v.capacity()<<" ";
    cout<<"size: "<<v.size()<<endl;
    v.push_back(2);
    cout<<"capacity: "<<v.capacity()<<" ";
    cout<<"size: "<<v.size()<<endl;
    v.emplace_back(3);
    cout<<"capacity: "<<v.capacity()<<" ";
    cout<<"size: "<<v.size()<<endl;

    vector<pair<int, int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(3,4);

    vector<int> v1(5, 100); // 5 instances of value 100
    vector<int> v2(5); // 5 instances as 0 or any garbage value
    vector<int> v3(5,20);
    vector<int> v4(v3); // another container copy of v3
    
    vector<int> vec1 = {20, 10, 15, 6, 7};
    vector<int>:: iterator it = vec1.begin();
    cout<<*(it)<<endl;
    it++;
    cout<<*(it)<<endl;
    it++;
    cout<<*(it)<<endl;

    vector<int>:: iterator it1 = vec1.end();
    it1--;
    cout<<*(it1)<<endl;

    vector<int>:: reverse_iterator it2 = vec1.rend();
    it2--;//it moves in reverse direction
    cout<<*(it2)<<endl;

    vector<int>:: reverse_iterator it3 = vec1.rbegin();
    cout<<*(it3)<<endl;
    it3++;//it moves in reverse direction
    cout<<*(it3)<<endl;

    vector<int> vec2 = {1,2,3,4,5,6};
    cout<<vec2[0]<<" "<<vec2.at(1)<<" "<<vec2.front()<<" "<<vec2.back()<<endl;
    for(vector<int>:: iterator it=vec2.begin();it!=vec2.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(auto it=vec2.begin();it!=vec2.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(auto ele:vec2)
    {
        cout<<ele<<" ";
    }
    cout<<endl;

    vector<int> vec3 = {10,20,30,40,50,60,70};
    vec3.erase(vec3.begin());
    for(auto it:vec3)
        cout<<it<<" ";
    //{20,30,40,50,60}
    cout<<endl;
    vec3.erase(vec3.begin()+1,vec3.begin()+3);
    for(auto it:vec3)
        cout<<it<<" ";
    //{20,50,60,70}
    cout<<endl;
    vec3.insert(vec3.begin(),300);
    for(auto it:vec3)
        cout<<it<<" ";
    //{300,20,50,60,70}
    cout<<endl;
    vec3.insert(vec3.begin()+1,2,100);
    for(auto it:vec3)
        cout<<it<<" ";
    //{300,100,100,20,50,60,70}
    cout<<endl;
    vector<int> copy = {55,60};
    vec3.insert(vec3.begin(),copy.begin(),copy.end());
    for(auto it:vec3)
        cout<<it<<" ";
    //{55,60,300,100,100,20,50,60,70}
    cout<<endl;
    vec3.pop_back();
    for(auto it:vec3)
        cout<<it<<" ";
    //{55,60,300,100,100,20,50,60}
    cout<<endl;
    cout<<vec3.size()<<endl;
    vector<int> vec4={1,2}, vec5={3,4};
    vec4.swap(vec5);
    vec4.clear();//erases the entire vector
    vector<int> g={};
    cout<<g.empty();//checks whether the container is empty or not
}

int main()
{
    explainVector();
}