#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    
    return a.second > b.second;
}

int solution(vector<vector<int>> res)
{
    vector<pair<int, int>> v;
    for (auto to : res)
        v.push_back({ to[0], to[1] });
    
    int a = v[0].first, b = v[0].second;
    sort(v.begin(), v.end(), cmp);
    
    int n = v.size();
    int ans = 1, mx = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (a < v[i].first && b < v[i].second)
            return -1;
        
        if (mx <= v[i].second)
        {
            if (a + b < v[i].first + v[i].second)
                ans++;
            mx = max(mx, v[i].second);
        }
    }
    
    return ans;
}