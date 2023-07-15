#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> p)
{
    bool ans = true;
    map<string, bool> mp;
    for (auto to : p) mp[to] = true;
    for (auto &to : p)
    {
        for (int i = 0; i < to.size(); i++)
        {
            string s = to.substr(0, i + 1);
            if (mp.count(s) && to != s) 
            {
                ans = false;
                break;
            }
        }
        if (!ans)
            break;
    }
    
    return ans;
}