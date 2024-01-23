#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll N = 100002;
pll a[N], dp[N];
ll n, k;

bool cmpA(pll &a, pll &b) // 2개수 우선
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second < b.second;
}

bool cmpB(pll &a, pll &b) // 5개수 우선
{
    if (a.second != b.second)
        return a.second < b.second;

    return a.first < b.first;
}

void init()
{
    for (int i = 0; i < N; i++)
        dp[i] = pll(-1, -1);
}

pll solve(ll idx, ll c)
{
    pll &ret = dp[idx];
    if (ret != pll(-1, -1))
        return ret;

    ret = a[idx];

    if (idx == n - 1)
        return ret;

    pll res = pll(1e9, 1e9);

    for (ll i = idx + 1; i <= idx + k; i++)
    {
        if (i >= n) break;
        pll tmp = solve(i, c);
        if (c == 2 && cmpA(tmp, res)) res = tmp;
        else if (c == 5 && cmpB(tmp, res)) res = tmp;
    }

    ret.first += res.first;
    ret.second += res.second;

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            ll cnt2 = 0, cnt5 = 0;
            while (x % 2 == 0) {
                cnt2++;
                x /= 2;
            }
            while (x % 5 == 0) {
                cnt5++;
                x /= 5;
            }
            a[i] = pll(cnt2, cnt5);
        }

        init();
        pll res1 = solve(0, 2);
        ll ans1 = min(res1.first, res1.second);

        init();
        pll res2 = solve(0, 5);
        ll ans2 = min(res2.first, res2.second);

        cout << min(ans1, ans2) << "\n";
    }
}
