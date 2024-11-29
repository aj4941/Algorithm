#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1000002;
ll ans[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(ans, -1, sizeof ans);
    ll n; cin >> n;
    queue<ll> q;
    for (int i = 0; i < 10; i++) q.push(i);
    ll idx = 0;
    while (!q.empty())
    {
        ll x = q.front(); q.pop();
        ans[idx++] = x;
        for (ll nx = 0; nx < (x % 10); nx++)
            q.push(x * 10 + nx);
    }

    cout << ans[n];
}