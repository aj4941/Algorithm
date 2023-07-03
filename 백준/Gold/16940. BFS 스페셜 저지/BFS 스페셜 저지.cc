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
const int N = 200002;
int n;
vector<int> g[N];
int p[N];
bool cache[N];

bool cmp(int &a, int &b)
{
    return p[a] < p[b];
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
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
        p[res[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end(), cmp);

    queue<int> q; q.push(1);
    vector<int> ans = { 1 }; cache[1] = true;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int nv : g[v])
        {
            if (cache[nv]) continue;
            q.push(nv); cache[nv] = true;
            ans.push_back(nv);
        }
    }

    if (ans == res) cout << 1;
    else cout << 0;
}