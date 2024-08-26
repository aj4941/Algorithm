#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 30002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int p[N], sz[N], cnt[N];
int dp[3002];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i, sz[i] = 1;
        cin >> cnt[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        u = find(u), v = find(v);
        if (u != v)
        {
            p[u] = v;
            sz[v] += sz[u], sz[u] = 0;
            cnt[v] += cnt[u], cnt[u] = 0;
        }
    }

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            res.push_back(i);
    }

    int mn = min(k - 1, 3000);

    int ans = 0;

    for (int i = 0; i < res.size(); i++)
    {
        int points = cnt[res[i]], humans = sz[res[i]];
        for (int num = mn; num >= humans; num--)
            dp[num] = max(dp[num], dp[num - humans] + points);
    }

    cout << dp[mn];
}