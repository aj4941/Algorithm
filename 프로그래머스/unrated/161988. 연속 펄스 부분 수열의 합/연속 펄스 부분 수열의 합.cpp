#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(vector<int> v) 
{
    vector<ll> a, b;
    for (ll i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            a.push_back(-v[i]);
            b.push_back(v[i]);
        }
        else
        {
            a.push_back(v[i]);
            b.push_back(-v[i]);
        }
    }
    
    ll ans = 0, asum = 0,bsum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        asum += a[i]; bsum += b[i];
        if (asum < 0) asum = 0;
        if (bsum < 0) bsum = 0;
        ans = max(ans, max(asum, bsum));
    }
    
    return ans;
}