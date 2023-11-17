#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

vector<int> solution(string msg) 
{
    for (int i = 0; i < 26; i++)
    {
        string s = to_string(i + 'A');
        mp[s] = i + 1;
    }
    
    int idx = 0, n_idx = 27;
    vector<int> ans;
    
    while (true)
    {
        string s = to_string(msg[idx++]);
        int c_idx = mp[s];
        while (idx < msg.size())
        {
            s += msg[idx];
            if (!mp.count(s))
            {
                mp[s] = n_idx++;
                break;
            }
            c_idx = mp[s]; idx++;
        }
        ans.push_back(c_idx);
        
        if (idx == msg.size())
            return ans;
    }
}