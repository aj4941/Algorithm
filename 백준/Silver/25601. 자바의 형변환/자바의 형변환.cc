#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<string, vector<string>> g;

bool dfs(string s, string f)
{
    bool result = false;
    if (s == f) return true;
    for (string ns : g[s])
        result |= dfs(ns, f);

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        string u, v; cin >> u >> v;
        g[v].push_back(u);
    }

    string s, t; cin >> s >> t;
    if (dfs(s, t) || dfs(t, s))
        cout << 1;
    else
        cout << 0;
}