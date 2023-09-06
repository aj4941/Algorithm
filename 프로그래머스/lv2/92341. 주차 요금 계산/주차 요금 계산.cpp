#include <bits/stdc++.h> 
using namespace std;
map<string, int> mp, cache;
const int MAX = 23 * 60 + 59;

int calc(string s)
{
    string h = s.substr(0, 2);
    string m = s.substr(3);
    return stoi(h) * 60 + stoi(m);
}

void solve(string s)
{
    stringstream sr(s);
    vector<string> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(w);
    
    int t = calc(v[0]);
    string num = v[1], cmd = v[2];
    
    if (cmd == "IN")
        cache[num] = t;
    else
    {
        mp[num] += t - cache[num];
        cache[num] = -1;
    }
}

int fee_calc(int value, vector<int> &fees)
{
    // cout << fees[0] << ' ' << fees[1] << ' ' << fees[2] << ' ' << fees[3] << endl;
    if (value <= fees[0])
        return fees[1];
    
    int res = fees[1]; value -= fees[0];
    res += (value + fees[2] - 1) / fees[2] * fees[3];
    
    return res;
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    for (auto to : records) solve(to);
    for (auto to : cache)
    {
        if (to.second != -1)
            mp[to.first] += MAX - to.second;
    }
    vector<int> ans;
    
    for (auto to : mp)
        ans.push_back(fee_calc(to.second, fees));
    
    return ans;
}