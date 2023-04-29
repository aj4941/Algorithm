#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 10987654321

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll X, Y; cin >> X >> Y;
    if (Y * 100 / X >= 99) cout << -1;
    else
    {
        ll Z = Y * 100 / X;
        ll ans = (X * Z + X - 100 * Y) / (100 - Z - 1);
        if ((X * Z + X - 100 * Y) % (100 - Z - 1)) ans++;
        cout << ans;
    }
}