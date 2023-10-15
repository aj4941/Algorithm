#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
unordered_map<string, bool> cache;

int solution(string st, string ed, vector<string> words) 
{
    for (auto to : words) cache[to] = true;
    queue<string> q; q.push(st);
    mp[st] = 0;
    while (!q.empty())
    {
        string v = q.front(); q.pop();
        for (int i = 0; i < v.size(); i++)
        {
            string nv = v;
            for (int j = 0; j < 26; j++)
            {
                nv[i] = (char)(j + 'a');
                if (!cache[nv] || mp.count(nv)) continue;
                mp[nv] = mp[v] + 1;
                q.push(nv);
            }
        }
    }
    
    return mp[ed];
}