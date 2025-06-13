#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to check if character is operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Helper function to get precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Infix to Postfix
string infixToPostfix(const string &s)
{
    stack<char> stk;
    string ans = "";
    for (char ch : s)
    {
        if (isalnum(ch))
            ans += ch;
        else if (ch == '(')
            stk.push(ch);
        else if (ch == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                ans += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
            {
                ans += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

// Infix to Prefix
string infixToPrefix(const string &s)
{
    string expr = s;
    reverse(expr.begin(), expr.end());
    for (char &ch : expr)
    {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }
    stack<char> stk;
    string ans = "";
    for (char ch : expr)
    {
        if (isalnum(ch))
        {
            ans += ch;
        }
        else if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                ans += stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            while (!stk.empty() &&
                   ((precedence(ch) < precedence(stk.top())) ||
                    (precedence(ch) == precedence(stk.top()) && ch == '^')))
            {
                ans += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Postfix to Infix
string postfixToInfix(const string &s)
{
    stack<string> stk;
    for (char ch : s)
    {
        if (isalnum(ch))
            stk.push(string(1, ch));
        else
        {
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            string expr = "(" + t2 + ch + t1 + ")";
            stk.push(expr);
        }
    }
    return stk.top();
}

// Prefix to Infix
string prefixToInfix(const string &s)
{
    int i = 0;
    stack<string> stk;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalnum(s[i]))
            stk.push(string(1, s[i]));
        else
        {
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            string expr = "(" + t1 + s[i] + t2 + ")";
            stk.push(expr);
        }
    }
    return stk.top();
}

// Postfix to Prefix
string postfixToPrefix(const string &s)
{
    stack<string> stk;
    for (char ch : s)
    {
        if (isalnum(ch))
            stk.push(string(1, ch));
        else
        {
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            string expr = ch + t2 + t1;
            stk.push(expr);
        }
    }
    return stk.top();
}

// Prefix to Postfix
string prefixToPostfix(const string &s)
{
    int i = 0;
    stack<string> stk;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalnum(s[i]))
            stk.push(string(1, s[i]));
        else
        {
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            string expr = t1 + t2 +s[i];
            stk.push(expr);
        }
    }
    return stk.top();
}

int main()
{
    // Example test cases for each function
    // Assuming these functions are defined elsewhere and return std::string

    // infixToPostfix
    string infix1 = "a+b*(c^d-c)";
    string postfixAns = infixToPostfix(infix1);
    cout << "Infix to Postfix of \"" << infix1 << "\": " << postfixAns << endl;

    // infixToPrefix
    string infix2 = "(a+b)*c-d+f";
    string prefixAns = infixToPrefix(infix2);
    cout << "Infix to Prefix of \"" << infix2 << "\": " << prefixAns << endl;

    // postfixToInfix
    string postfix1 = "ab-de+f*/";
    string infixFromPostfix = postfixToInfix(postfix1);
    cout << "Postfix to Infix of \"" << postfix1 << "\": " << infixFromPostfix << endl;

    // prefixToInfix
    string prefix1 = "*+pq-mn";
    string infixFromPrefix = prefixToInfix(prefix1);
    cout << "Prefix to Infix of \"" << prefix1 << "\": " << infixFromPrefix << endl;

    // postfixToPrefix
    string postfix2 = "ab-de+f*/";
    string prefixFromPostfix = postfixToPrefix(postfix2);
    cout << "Postfix to Prefix of \"" << postfix2 << "\": " << prefixFromPostfix << endl;

    // prefixToPostfix
    string prefix2 = "/-ab*+def";
    string postfixFromPrefix = prefixToPostfix(prefix2);
    cout << "Prefix to Postfix of \"" << prefix2 << "\": " << postfixFromPrefix << endl;

    return 0;
}