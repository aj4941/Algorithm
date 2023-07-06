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
const int N = 200002;
ll n, k, cnt[N];
vector<int> g[N];

void dfs(int v, ll c)
{
    int lv = g[v][0], rv = g[v][1];
    if (lv == -1 && rv == -1) return;
    if (lv == -1) cnt[rv] = c, dfs(rv, cnt[rv]);
    else if (rv == -1) cnt[lv] = c, dfs(lv, cnt[lv]);
    else
    {
        cnt[lv] = (c + 1) / 2, cnt[rv] = c / 2;
        dfs(lv, cnt[lv]); dfs(rv, cnt[rv]);
    }
}

int find(int v)
{
    int lv = g[v][0], rv = g[v][1];
    if (lv == -1 && rv == -1) return v;
    if (lv == -1) return find(rv);
    if (rv == -1) return find(lv);
    if (cnt[lv] <= cnt[rv]) return find(lv);
    else return find(rv);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        g[i].push_back(x);
        g[i].push_back(y);
    }
    cin >> k; dfs(1, k - 1);

    cout << find(1);
}