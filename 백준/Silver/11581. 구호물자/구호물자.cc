#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool hasAns = true;
const int N = 200;
vector<int> g[N];
bool cache[N], cache2[N];

void dfs(int v)
{
    for (int nv : g[v])
    {
        if (cache[nv]) continue;
        cache[nv] = true;
        dfs(nv);
    }
}

void cycle(int v)
{
    for (int nv : g[v])
    {
        if (cache2[nv]) continue;
        cache2[nv] = true;
        cycle(nv);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int v = 1; v < n; v++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int nv; cin >> nv;
            g[v].push_back(nv);
        }
    }

    cache[1] = true;
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (cache[i])
        {
            memset(cache2, false, sizeof cache2);
            cycle(i);
            if (cache2[i]) hasAns = false;
        }
    }

    if (hasAns) cout << "NO CYCLE";
    else cout << "CYCLE";
}