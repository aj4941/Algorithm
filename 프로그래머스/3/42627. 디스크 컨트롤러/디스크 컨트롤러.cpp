#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
int t = 0;

bool cmp(pii &a, pii &b)
{
    if (a.first <= t && b.first > t)
        return true;
    if (a.first > t && b.first <= t)
        return false;
    if (a.first <= t && b.first <= t)
        return a.second < b.second;
    
    if (a.first != b.first)
        return a.first < b.first;
    
    return a.second < b.second;
}

int solution(vi jobs) 
{   
    int ans = 0;
    vector<pii> v;
    for (auto to : jobs)
    {
        int ct = to[0], w = to[1];
        v.push_back({ ct, w });
    }
    
    int n = v.size();
    
    while (v.size() > 0)
    {
        sort(v.begin(), v.end(), cmp);
        auto to = *v.begin();
        int nt = (max(to.first, t) + to.second);
        ans += nt - to.first;
        v.erase(v.begin());
        t = nt;
    }
    
    return ans / n;
}