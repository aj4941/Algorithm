#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<pll>> graph(100002);
bool visit[100002];
ll length = 0, longest;

void dfs(int v, ll len)
{
    visit[v] = true;
    for(auto to : graph[v])
    {
        if(!visit[to.first])
            dfs(to.first, len + to.second);
    }
    if(length < len)
    {
        length = len;
        longest = v;
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t; cin >> t;
    while(t--)
    {
        ll u, v, w; cin >> u;
        while(true)
        {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            graph[u].push_back({ v, w });
        }
    }
    dfs(1, 0);
    memset(visit, false, sizeof visit);
    dfs(longest, 0);
    cout << length;
}