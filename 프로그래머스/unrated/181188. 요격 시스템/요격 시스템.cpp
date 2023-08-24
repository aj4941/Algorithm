#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solution(vector<vector<int>> t) 
{
    vector<pii> v; 
    
    for (auto to : t)
    {
        int x = to[0], y = to[1];
        v.push_back({ x, y });
        // cout << "pos : " << x << ' ' << y << endl;
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0, ed = -1e9;
    
    for (auto to : v)
    {
        if (to.first >= ed)
        {
            ans++;
            ed = to.second;
            continue;
        }
        
        ed = min(ed, to.second);
    }
    
    return ans;
}