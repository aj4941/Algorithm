#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool check[1200];
vector<vector<int>> graph(1200);

void dfs(int v)
{
    check[v] = true;
    for(int to : graph[v])
    {
        if(!check[to])
            dfs(to);
    }
}
int main(void)
{  
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!check[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}