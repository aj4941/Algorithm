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
const int N = 1000002;
ll g[N];

void calc(ll x)
{
    ll res = 0, sx = x;
    while (x > 0)
    {
        ll cx = x % 10;
        res += cx * cx; x /= 10;
    }
    g[sx] = res;
}

vector<int> stk;
int cache[N], cycle[N];

void dfs(int v)
{
    cache[v] = 1;
    stk.push_back(v);
    int nv = g[v];
    if (cache[nv] == 1)
    {
        vector<int> tmp;
        while (stk.back() != nv)
        {
            int x = stk.back();
            cycle[x] = 2; tmp.push_back(x);
            stk.pop_back();
        }
        cycle[stk.back()] = 2; tmp.push_back(stk.back());
        stk.pop_back();

        while (!tmp.empty())
        {
            stk.push_back(tmp.back());
            tmp.pop_back();
        }
    }
    else if (nv != -1 && cache[nv] == 0)
        dfs(nv);

    stk.pop_back();
    cache[v] = 2;
}

int p[N];

int solve(int x)
{
    if (cycle[x] == 2) return 2;
    int nx = g[x];
    if (nx == -1 || cycle[nx] == 1) return cycle[x] = 1;
    else return cycle[x] = solve(nx);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    g[1] = -1;

    for (int i = 2; i < N; i++)
    {
        calc(i);
        p[i] = i;
    }

    for (int i = 2; i < N; i++) dfs(i);
    // for (int i = 2; i <= 100; i++) cout << i << ' ' << cycle[i] << endl;

    for (int i = 2; i < N; i++)
    {
        if (p[i] != i) continue;
        for (int j = i + i; j < N; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }

    int n; cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == i)
        {
            if (solve(i) == 1)
                cout << i << "\n";
        }
    }
}