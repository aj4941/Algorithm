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
const int N = 1000;
int k, n, f;
vector<int> g[N];
bool cache[N];

// 선택된 정점 ( 연결 정점
void dfs(int v, int c)
{
    if (c == k)
    {
        for (int i = 1; i < N; i++)
        {
            if (cache[i])
                cout << i << "\n";
        }
        exit(0);
    }

    for (int nv : g[v])
    {
        if (cache[nv]) continue;
        if (g[nv].size() < k - 1) continue;
        int cnt = 0;
        for (int nnv : g[nv])
        {
            if (cache[nnv])
                cnt++;
        }
        if (cnt == c)
        {
            cache[nv] = true;
            dfs(nv, c + 1);
            cache[nv] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> k >> n >> f;

    for (int i = 0; i < f; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    for (int i = 1; i < N; i++)
        sort(g[i].begin(), g[i].end());

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() >= k - 1)
        {
            cache[i] = true;
            dfs(i, 1);
            cache[i] = false;
        }
    }

    cout << -1;
}