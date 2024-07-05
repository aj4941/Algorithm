#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const ll N = 10005;
bool cache[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    ll lcd = n * m / gcd(n, m);
    ll inc = lcd / n;
    for (int i = inc; i < lcd; i += inc)
        cache[i] = true;

    inc = lcd / m;

    ll ans = 0;

    for (int i = inc; i < lcd; i += inc)
    {
        if (cache[i]) continue;
        ans++;
    }

    cout << ans;
}