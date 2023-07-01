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
int dy[4] = { 0, -1, 0, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 4002;
int n, m;
vector<int> g[N];
bool hasAns = false;
bool cache[N];

void dfs(int v, int c)
{
    if (c == 5)
    {
        hasAns = true;
        return;
    }

    for (int nv : g[v])
    {
        if (cache[nv]) continue;
        cache[nv] = true;
        dfs(nv, c + 1);
        cache[nv] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (hasAns) break;
        cache[i] = true;
        dfs(i, 1);
        cache[i] = false;
    }

    if (hasAns) cout << 1;
    else cout << 0;
}