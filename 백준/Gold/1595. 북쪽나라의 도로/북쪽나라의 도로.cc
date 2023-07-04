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
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 10002;
vector<pii> g[N];
int len = 0, A = -1;

void dfs(int v, int p, int d)
{
    if (len < d)
    {
        len = d;
        A = v;
    }

    for (auto to : g[v])
    {
        int nv = to.first, w = to.second;
        if (nv == p) continue;
        dfs(nv, v, d + w);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    dfs(1, 0, 0); dfs(A, 0, 0);
    cout << len;
}