#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1000002;
int mobius[N] = { 0 };

void init()
{
    mobius[1] = 1;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 2 * i; j <= N; j += i)
            mobius[j] -= mobius[i];
    }
}

ll calc(ll n)
{
    ll counts = 0;
    for (ll i = 1; i * i <= n; i++) {
        counts += mobius[i] * (n / (i * i));
    }
    return counts;
}

int main(void)
{
    init();
    ll k; cin >> k;
    ll l = 0, r = 1e12;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (calc(mid) < k)l = mid;
        else r = mid;
    }
    cout << r;
}
