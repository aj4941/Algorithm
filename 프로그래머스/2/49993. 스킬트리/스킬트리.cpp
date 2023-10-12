#include <bits/stdc++.h>
using namespace std;
int cache[30];

int solution(string s, vector<string> st) 
{
    int idx = 1;
    for (auto to : s)
        cache[to - 'A'] = idx++;
    
    int ans = 0;
    
    for (auto to : st)
    {
        bool hasAns = true;
        int idx = 0;
        
        for (int i = 0; i < to.size(); i++)
        {
            if (!cache[to[i] - 'A']) continue;
            if (s[idx] == to[i]) idx++;
            if (idx == s.size()) break;
            if (cache[s[idx] - 'A'] < cache[to[i] - 'A']) 
            {
                hasAns = false;
                break;
            }
        }
        
        if (hasAns)
        {
            // cout << to << endl;
            ans++;
        }
    }
    
    return ans;
}