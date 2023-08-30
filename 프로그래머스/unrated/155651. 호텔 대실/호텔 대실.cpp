#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int calc(string s)
{
    stringstream sr(s);
    string w;
    vector<string> v;
    while (getline(sr, w, ':'))
        v.push_back(w);
    
    return stoi(v[0]) * 60 + stoi(v[1]);
}

int solution(vector<vector<string>> s) 
{
    vector<pii> tmp;
    
    for (auto to : s)
    {
        string r1 = to[0], r2 = to[1];
        int st = calc(r1), ed = calc(r2) + 10;
        tmp.push_back({ st, ed });
    }
    
    sort(tmp.begin(), tmp.end());
    priority_queue<int> pq;
    
    int ans = 0;
    
    for (int i = 0; i < tmp.size(); i++)
    {
        int st = tmp[i].first, ed = tmp[i].second;
        if (pq.size() == 0)
        {
            pq.push(-ed);
            ans = 1;
        }
        else
        {
            int mn = -pq.top();
            if (mn <= st) pq.pop();
            pq.push(-ed);
            ans = max(ans, (int)pq.size());
        }
    }
    
    return ans;
}