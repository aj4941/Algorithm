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
const int N = 100002;
vector<int> g[N], res;
map<pii, int> mp;
int n;
int idx = 1;

void dfs(int v)
{
    // cout << v << ' ' << idx << endl;
    while (true)
    {
        if (idx == n) return;
        if (!mp.count({v, res[idx]})) return;
        dfs(res[idx++]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
        mp[{ u, v }] = 1; mp[{ v, u }] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        res.push_back(x);
    }

    dfs(1);

    if (idx == n) cout << 1;
    else cout << 0;
}