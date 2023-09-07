#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> solution(int n, ll l, ll r)
{
    vector<int> ans;
    
    for (ll val = l; val <= r; val++)
    {
        int x = val / n, y = val % n;
        int mx = max(x, y);
        ans.push_back(mx + 1);
    }
    
    return ans;
}