#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) for insertion in worst case
    // SC: O(n) due to recursion stack
    void insert(int element, stack<int> &st)
    {
        if (st.empty() || st.top() < element)
        {
            st.push(element);
            return;
        }

        int topElement = st.top();
        st.pop();
        insert(element, st);
        st.push(topElement);
    }

    // TC: O(n^2)
    // SC: O(n)
    void sorting(stack<int> &st)
    {
        // Base case
        if (st.empty() || st.size() == 1)
        {
            return;
        }

        int topElement = st.top();
        st.pop();

        sorting(st);
        insert(topElement, st);
    }

    void sortStack(stack<int> &st)
    {
        sorting(st);
    }
};

int main()
{
    Solution obj;
    stack<int> st;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    obj.sortStack(st);

    // Printing sorted stack (top to bottom)
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}