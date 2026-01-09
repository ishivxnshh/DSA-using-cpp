#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertAtBottomOfStack(int topElement, stack<int> &st)
    {
        if (st.empty())
        {
            st.push(topElement);
            return;
        }

        int topp = st.top();
        st.pop();
        insertAtBottomOfStack(topElement, st);
        st.push(topp);
    }

    void reverseStack(stack<int> &st)
    {
        // code here
        if (st.empty()) return;

        int topElement = st.top(); 
        st.pop();

        reverseStack(st);

        // stack<int> temp;
        // while (!st.empty())
        // {
        //     temp.push(st.top()); 
        //     st.pop();
        // }
        // st.push(topElement);
        // while (!temp.empty())
        // {
        //     st.push(temp.top()); 
        //     temp.pop();
        // }

        insertAtBottomOfStack(topElement, st); // Auxiliary Space: O(1)
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

    obj.reverseStack(st);

    // Printing reversed stack (top to bottom)
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}