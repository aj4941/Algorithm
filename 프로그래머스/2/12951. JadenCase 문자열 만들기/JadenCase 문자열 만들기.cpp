#include <bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    string ans = "";
    bool flag = false;
    int len = 0;
    for (auto to : s)
    {
        if (flag) 
        {
            if ('A' <= to && to <= 'Z')
                to = to - 'A' + 'a';
            
            ans += to;
        }
        else // 첫 문자
        {
            if (to == ' ') ans += to;
            else 
            {
                if ('a' <= to && to <= 'z')
                    to = to - 'a' + 'A';
                ans += to;
                
                flag = true;
            }
        }
        if (to == ' ')
            flag = false;
    }
    
    return ans;
}