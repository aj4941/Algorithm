#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 100002;
const ll inf = 1000000007;
ll cnt[N];
ll n, k;

ll mpow(ll a, ll x)
{
    if (x == 0) return 1;
    ll res = mpow(a, x / 2);
    res = res * res % inf;
    if (x % 2) res = res * a % inf;
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        cnt[x % k]++;
    }

    ll ans = 1 + cnt[0];

    for (int i = 1; i <= k / 2; i++)
    {
        if (i + i == k) break;
        ans *= (1 + (mpow(2, cnt[i]) - 1) + (mpow(2, cnt[k - i]) - 1));
        ans %= inf;
    }

    if (k / 2 + k / 2 == k)
    {
        ans *= (1 + cnt[k / 2]);
        ans %= inf;
    }

    ans = (ans - 1 + inf) % inf;
    for (int i = 0; i < k; i++)
        ans = (ans - cnt[i] + inf) % inf;

    cout << ans;
}