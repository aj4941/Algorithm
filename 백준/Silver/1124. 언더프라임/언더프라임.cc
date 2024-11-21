#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007
const ll N = 100002;
ll p[N], dp[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (ll i = 2; i < N; i++) p[i] = i;
    for (ll i = 2; i < N; i++)
    {
        if (p[i] != i) continue;
        for (ll j = i + i; j < N; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }
    
    dp[1] = 0;
    for (ll i = 2; i < N; i++) dp[i] = dp[i / p[i]] + 1;

    ll A, B; cin >> A >> B;
    ll ans = 0;

    for (ll i = A; i <= B; i++)
    {
        if (p[dp[i]] == dp[i])
            ans++;
    }

    cout << ans;
}