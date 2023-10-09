#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll solution(int w, int h) 
{
    ll ans = (ll)w * (ll)h;
    ll g = gcd(w, h);
    ll sw = w / g, sh = h / g;
    ll mx = max(sw, sh), mn = min(sw, sh);
    ans -= g * (mx + (mn - 1));
    return ans;
}