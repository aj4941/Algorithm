#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 252;
bool cache[N][N];
ll r, c;
string s[N];

pll dfs(ll x, ll y)
{
    cache[x][y] = true;
    ll sheep = 0, wolf = 0;
    if (s[x][y] == 'v') wolf++;
    else if (s[x][y] == 'k') sheep++;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (cache[nx][ny] || s[nx][ny] == '#') continue;
        cache[nx][ny] = true;
        pll res = dfs(nx, ny);
        sheep += res.first, wolf += res.second;
    }
    return { sheep, wolf };
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> r >> c;
    for (ll i = 0; i < r; i++) cin >> s[i];

    ll sheep = 0, wolf = 0;

    for (ll i = 0; i < r; i++) for (ll j = 0; j < c; j++)
    {
        if (s[i][j] == '#' || cache[i][j]) continue;
        pll res = dfs(i, j);
        if (res.first > res.second) sheep += res.first;
        else wolf += res.second;
    }

    cout << sheep << ' ' << wolf;
}