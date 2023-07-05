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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200;
vector<int> g[N];
int n, cache[N];

void dfs(int v)
{
    if (v > n)
    {
        vector<int> a, b;
        for (int i = 1; i <= n; i++)
        {
            if (cache[i] == 1) a.push_back(i);
            else b.push_back(i);
        }

        cout << a.size() << "\n";
        for (auto to : a) cout << to << ' ';

        cout << "\n" << b.size() << "\n";
        for (auto to : b) cout << to << ' ';

        if (a.size() == 0 || b.size() == 0) return;

        exit(0);
    }

    bool one = true, two = true;

    for (int nv : g[v])
    {
        if (cache[nv] == 1) one = false;
        if (cache[nv] == 2) two = false;
    }

    if (one)
    {
        cache[v] = 1;
        dfs(v + 1);
        cache[v] = 0;
    }
    if (two)
    {
        cache[v] = 2;
        dfs(v + 1);
        cache[v] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int x; cin >> x;
            g[i + 1].push_back(x);
            g[x].push_back(i + 1);
        }
    }

    dfs(1);
}