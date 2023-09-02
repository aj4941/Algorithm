#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool calc(ll x, ll y, ll d)
{
    if (x * x + y * y <= d * d)
        return true;
    return false;
}

ll solution(int k, int d) 
{
    ll ans = 0;
    
    for (int x = 0; x <= d; x += k)
    {
        int l = 0, r = 1e7;
        while (l + 1 < r) // [l, r)
        {
            int mid = (l + r) / 2;
            if (calc(x, mid * k, d)) l = mid;
            else r = mid;
        }
        // cout << "l : " << l << endl;
        // cout << x << ' ' << k * l << endl;
        ans += l + 1;
    }
    return ans;
}