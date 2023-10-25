#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;
string s[60];
int dp[60][60];
bool cache[60][60];

int dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == 'H')
        return 0;
    if (cache[x][y])
    {
        cout << -1;
        exit(0);
    }
    int& ret = dp[x][y];
    int val = s[x][y] - '0';
    if (ret != -1) return ret;
    cache[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * val, ny = y + dy[i] * val;
        ret = max(ret, dfs(nx, ny) + 1);
    }
    cache[x][y] = false;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    memset(cache, false, sizeof cache);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    cout << dfs(0, 0);
}