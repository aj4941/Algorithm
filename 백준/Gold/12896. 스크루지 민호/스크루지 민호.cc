#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };
const int N = 200002;
vector<int> g[N];
int n;
int mx_len = -1, mx_v = -1;

void dfs(int v, int p, int d)
{
    if (mx_len < d)
    {
        mx_len = d;
        mx_v = v;
    }
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dfs(nv, v, d + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0, 0);
    dfs(mx_v, 0, 0);

    cout << (mx_len + 1) / 2;
}