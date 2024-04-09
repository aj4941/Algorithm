#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool check[2000];
vector<vector<int>> graph(2000);

void dfs(int v)
{
    cout << v << " ";
    check[v] = true;
    for(int to : graph[v])
    {
        if(!check[to])
            dfs(to);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    check[v] = true;
    while(!q.empty())
    {
        int top = q.front(); q.pop();
        cout << top << " ";
        for(int to : graph[top])
        {
            if(!check[to])
            {
                q.push(to);
                check[to] = true;
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, v; cin >> n >> m >> v;
    for(int i = 0; i < m; i++)
    {
        int U, V; cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
    dfs(v); cout << "\n";
    memset(check, false, sizeof check);
    bfs(v);
}