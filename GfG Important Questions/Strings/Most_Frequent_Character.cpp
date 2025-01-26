//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string s)
    {
        int freq[26] = {0};
        for(char ch : s)
        {
            freq[ch - 'a']++;
        }
        int max_freq = 0;
        char result = 'a';
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > max_freq)
            {
                max_freq = freq[i];
                result = 'a' + i;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends