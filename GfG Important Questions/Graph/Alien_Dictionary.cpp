#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

// ---------- Solution Class ----------
class Solution {
public:
    string findOrder(vector<string> &words) {
        set<char> unique_chars;
        for (auto word : words) {
            for (auto ch : word) {
                unique_chars.insert(ch);
            }
        }

        unordered_map<char, int> charToIndex;
        unordered_map<int, char> indexToChar;
        int idx = 0;
        for (char ch : unique_chars) {
            charToIndex[ch] = idx;
            indexToChar[idx] = ch;
            idx++;
        }

        int k = unique_chars.size();
        vector<vector<int>> adj(k);
        vector<int> inOrder(k, 0);

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            if (s1.substr(0, len) == s2.substr(0, len) && s1.length() > s2.length())
            {
                return "";
            }
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    int u = charToIndex[s1[j]];
                    int v = charToIndex[s2[j]];
                    adj[u].push_back(v);
                    inOrder[v]++;
                    break;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (inOrder[i] == 0) {
                q.push(i);
            }
        }

        string result = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result += indexToChar[node];

            for (int nbr : adj[node]) {
                inOrder[nbr]--;
                if (inOrder[nbr] == 0)
                    q.push(nbr);
            }
        }

        if (result.length() < k) return "";
        return result;
    }
};

// ---------- Driver Code ----------
int main() {
    Solution obj;
    
    // Sample test case
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    
    string order = obj.findOrder(words);
    
    if (order == "") {
        cout << "Invalid order or cycle detected." << endl;
    } else {
        cout << "Character order: " << order << endl;
    }

    return 0;
}