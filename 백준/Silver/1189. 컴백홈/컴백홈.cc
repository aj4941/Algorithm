#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int r, c, k;
string s[10];
int ans = 0;
bool cache[10][10];

void dfs(int x, int y, int d)
{
    if (x == 0 && y == c - 1 && d == k - 1)
    {
        ans++;
        return;
    }
    if (d > k) 
        return;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (s[nx][ny] == 'T' || cache[nx][ny]) continue;
        cache[nx][ny] = true;
        dfs(nx, ny, d + 1);
        cache[nx][ny] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) cin >> s[i];
    cache[r - 1][0] = true;
    dfs(r - 1, 0, 0); 
    cout << ans;
}