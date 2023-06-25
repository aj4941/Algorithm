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
const int N = 10002;
vector<int> g[N];
bool cache[N];
int res[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        memset(cache, false, sizeof cache);
        cache[i] = true;
        int cnt = 1;

        queue<int> q; q.push(i);
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (int nv : g[v])
            {
                if (cache[nv]) continue;
                cache[nv] = true;
                q.push(nv); cnt++;
            }
        }

        ans = max(ans, cnt);
        res[i] = cnt;
    }

    for (int i = 1; i <= n; i++)
    {
        if (res[i] == ans)
            cout << i << ' ';
    }
}