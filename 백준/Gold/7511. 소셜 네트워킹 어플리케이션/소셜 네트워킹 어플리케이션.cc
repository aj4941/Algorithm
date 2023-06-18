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
const int N = 1000005;
int p[N];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Scenario " << tc << ":" << "\n";
        int n; cin >> n;
        for (int i = 1; i <= n; i++) p[i] = i;
        int k; cin >> k;
        for (int i = 0; i < k; i++)
        {
            int u, v; cin >> u >> v; u++; v++;
            u = find(u), v = find(v);
            if (u == v) continue;
            p[u] = v;
        }

        int m; cin >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v; cin >> u >> v; u++; v++;
            if (find(u) == find(v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }

        cout << "\n";
    }
}