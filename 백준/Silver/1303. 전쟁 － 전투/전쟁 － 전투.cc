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
int dy[4] = { 0, -1, 0, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200;
int n, m;
string s[N];
bool cache[N][N];
ll cnt = 1;
ll W, B;

void dfs(int x, int y, char c)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (cache[nx][ny] || c != s[nx][ny]) continue;
        cache[nx][ny] = true; cnt++;
        dfs(nx, ny, c);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> s[i];

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
    {
        if (cache[i][j]) continue;
        cache[i][j] = true; cnt = 1;
        dfs(i, j, s[i][j]);

        if (s[i][j] == 'W') W += cnt * cnt;
        else B += cnt * cnt;
    }

    cout << W << ' ' << B;
}