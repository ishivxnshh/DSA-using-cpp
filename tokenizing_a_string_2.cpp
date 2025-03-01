#include <iostream>
#include <vector>
using namespace std;

vector<string> tokenizeString(const string &str, char delimiter = ' ') {
    vector<string> ans;
    int start = 0;
    int end = str.find(delimiter, start);
    while(end!=string::npos)
    {
        string temp = str.substr(start, end-start);
        ans.push_back(temp);
        start = end + 1;
        end = str.find(delimiter, start);
    }
    string temp = str.substr(start, end-start);
    ans.push_back(temp);
    return ans;
}  

int main() {  
    vector<string> tokens = tokenizeString("This is a test string");
    for (const auto &token : tokens)
        cout << token << endl;  
    return 0;  
}