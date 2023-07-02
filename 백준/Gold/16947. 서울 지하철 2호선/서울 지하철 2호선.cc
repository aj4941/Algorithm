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
const int N = 3002;
int n;
vector<int> g[N], stk;
int cache[N], dist[N];
bool cycle[N];

void dfs(int v, int p)
{
    stk.push_back(v);
    cache[v] = 1;
    for (int nv : g[v])
    {
        if (nv == p || cache[nv] == 2) continue;
        if (cache[nv] == 1)
        {
            vector<int> tmp;
            while (stk.back() != nv)
            {
                cycle[stk.back()] = true;
                tmp.push_back(stk.back()); stk.pop_back();
            }
            cycle[stk.back()] = true;
            tmp.push_back(stk.back()); stk.pop_back();

            while (tmp.size())
            {
                stk.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        else
            dfs(nv, v);
    }
    stk.pop_back();
    cache[v] = 2;
}

int d = 0;

void find(int v, int p)
{
    if (cycle[v]) return;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dfs(nv, v); d++;
        break;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    queue<int> q;
    memset(dist, -1, sizeof dist);

    for (int i = 1; i <= n; i++)
    {
        if (cycle[i])
        {
            q.push(i);
            dist[i] = 0;
        }
    }

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int nv : g[v])
        {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
}