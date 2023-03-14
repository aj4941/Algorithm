#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int solution(vector<int> a) {
    
    vector<pii> v;
    int n = a.size();
    if (n <= 2) return n;
    
    for (int i = 0; i < n; i++)
        v.push_back({ a[i], i });
    
    sort(v.begin(), v.end());

    int l = min(v[0].second, v[1].second);
    int r = max(v[0].second, v[1].second);
    int ans = 2;
    
    for (int i = 2; i < n; i++)
    {
        int idx = v[i].second;
        if (l <= idx && idx <= r) continue; 
        ans++; l = min(l, idx); r = max(r, idx);
    }
    
    return ans;
}