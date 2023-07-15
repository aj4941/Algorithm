#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> p, vector<string> c) 
{
    map<string, int> mp;
    for (auto to : p) mp[to]++;
    for (auto to : c) mp[to]--;
    for (auto to : p)
    {
        if (mp[to] > 0)
            return to;
    }
}