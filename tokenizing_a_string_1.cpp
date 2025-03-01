#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<string> tokenizeString(const string &str)  
{  
    vector<string> tokens;  
    stringstream ss(str);  
    string word;  

    while (ss >> word)  
    {  
        tokens.push_back(word);  
    }  

    return tokens;  
}  

int main()  
{  
    string text = "Hello, world! This is a test.";  
    vector<string> tokens = tokenizeString(text);  

    for (const string &token : tokens)  
    {  
        cout << token << endl;  
    }  

    return 0;  
}