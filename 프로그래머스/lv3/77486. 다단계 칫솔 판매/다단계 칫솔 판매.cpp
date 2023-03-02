#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
map<string, string> g;
map<string, ll> res;

vector<int> solution(vector<string> e, 
                     vector<string> r, vector<string> s, vector<int> a) 
{
    ll n = e.size();
    
    for (ll i = 0; i < n; i++)
        g[e[i]] = r[i];
    
    for (ll i = 0; i < s.size(); i++)
    {
        res[s[i]] += a[i] * 100;
        ll value = a[i] * 100;
        string v = s[i];
        while (true)
        {
            string nv = g[v];
            res[nv] += value / 10; 
            res[v] -= value / 10;
            value /= 10;
            if (nv == "-" || value < 10) break;
            v = nv;
        }
    }
    
    vector<int> ans;
    
    for (ll i = 0; i < n; i++)
        ans.push_back(res[e[i]]);
    
    return ans;
}