#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tll;
const int N = 100005;
ll p[N];
vector<ll> v;

ll mpow(ll a, ll x)
{
    if (x == 0) return 1;
    ll res = mpow(a, x / 2);
    res = res * res;
    if (x % 2) res = res * a;
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 2; i < N; i++) p[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (p[i] != i) continue;
        v.push_back(i);
        for (int j = i; j < N; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }

    ll n, k;
    while (!cin.eof() && cin >> n >> k)
    {
        ll ans = 1;
        for (auto to : v)
        {
            if (to > k) break;
            ll c1 = 0, c2 = 0;

            while (k % to == 0)
            {
                c1++;
                k /= to;
            }

            ll val = to;
            while (val <= n)
            {
                c2 += n / val;
                val *= to;
            }

            ans *= mpow(to, min(c1, c2));
        }

        if (k < n) ans *= k;
        
        cout << ans << "\n";
    }
}