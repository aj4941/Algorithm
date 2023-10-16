#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
vector<pii> v;

bool cmp(pii &a, pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    
    return a.first < b.first;
}

int solution(vi routes) 
{
    for (auto to : routes)
        v.push_back({ to[0], to[1] });
    
    sort(v.begin(), v.end(), cmp);
    
    int ed = -1e9;
    int ans = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        int s = v[i].first, e = v[i].second;
        if (s > ed)
        {
            ans++;
            ed = e;
        }
    }
    
    
    return ans;
}