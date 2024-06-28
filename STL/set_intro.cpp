#include <iostream>
#include <set>
using namespace std;
void explainSet() //(sorted + unique)
{
    set<int> st;
    st.insert(1); //{1}
    st.emplace(2); //{1,2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}
    st.insert(3); //{1,2,3,4}

    //auto it = st.find(3);
    //auto it1 = st.find(6);
    st.erase(5);

    int cnt = st.count(1); //1 or 0

    auto it = st.find(3);
    st.erase(it);

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); //erases from it1 to before it2

    auto it3 = st.lower_bound(2);
    auto it3 = st.upper_bound(3);

    for(auto it:st)
        cout<<it<<" ";

}

int main()
{
    explainSet();
}