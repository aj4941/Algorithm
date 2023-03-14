#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> p;

ll find(ll x)
{
    if (!p.count(x))
        return x;
    else
        return p[x] = find(p[x]);
}

vector<ll> solution(ll k, vector<ll> v) {
    
    vector<ll> ans;
    
    for (auto x : v)
    {
        ll fx = find(x);
        ans.push_back(fx);
        p[fx] = fx + 1;
    }
    
    return ans;
}