#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 300002;
vector<int> g[N];
ll D = 0, G = 0;
ll dp[N][5];

ll nCr(ll r, ll c)
{
    ll &ret = dp[r][c];
    if (ret != -1) return ret;
    if (r == c || c == 0) return ret = 1;
    return ret = nCr(r - 1, c) + nCr(r - 1, c - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto ni : g[i])
        {
            ll sz1 = (ll)g[i].size() - 1;
            ll sz2 = (ll)g[ni].size() - 1;
            D += sz1 * sz2;
        }
    }
    D /= 2;

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() < 3) continue;
        G += nCr(g[i].size(), 3);
    }

    if (D > G * 3) cout << "D";
    else if (D < G * 3) cout << "G";
    else cout << "DUDUDUNGA";
}