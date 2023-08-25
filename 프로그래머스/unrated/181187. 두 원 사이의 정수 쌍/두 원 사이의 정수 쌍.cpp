#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(int r1, int r2) 
{    
    ll ans = 0;
    
    for (ll x = 1; x <= r2 - 1; x++)
    {
        ll l = 0, r = 1e9;
        while (l + 1 < r) // [l, r)
        {
            ll mid = (l + r) / 2;
            if (x * x + mid * mid <= (ll)r2 * (ll)r2) l = mid;
            else r = mid;
        }
        ans += l * 4;
    }
    
    for (ll x = 1; x <= r1 - 1; x++)
    {
        ll l = 0, r = 1e9;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (x * x + mid * mid < (ll)r1 * (ll)r1) l = mid;
            else r = mid;
        }
        ans -= l * 4;
    }
    
    ans += (r2 - r1 + 1) * 4;
    return ans;
}