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
const int N = 500002;
ll n, W, cnt;
vector<ll> g[N];

void dfs(int v, int p)
{
    bool flag = true;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        flag = false;
        dfs(nv, v);
    }

    if (flag) cnt++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> W;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    double ans = (double) W / (double) cnt;
    cout << fixed << setprecision(3) << ans;
}