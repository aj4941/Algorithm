#include <bits/stdc++.h>
using namespace std;
int ans = 0;

void calc(string &s)
{
    char tmp = s[0];
    for (int i = 1; i < s.size(); i++)
        s[i - 1] = s[i];
    s[s.size() - 1] = tmp;
    
    vector<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push_back(s[i]);
        else
        {
            if (s[i] == ')')
            {
                if (stk.size() && stk.back() == '(')
                    stk.pop_back();
                else
                    return;
            }
            else if (s[i] == '}')
            {
                if (stk.size() && stk.back() == '{')
                    stk.pop_back();
                else
                    return;
            }
            else if (s[i] == ']')
            {
                if (stk.size() && stk.back() == '[')
                    stk.pop_back();
                else
                    return;
            }
        }
    }
    
    if (stk.size() == 0)
        ans++;
    
    return;
}

int solution(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++) calc(s);
    
    return ans;
}