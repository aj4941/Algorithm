#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pii a[50];
int n, k;
int dp[50][2];

int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    if (x > n) return ret = 1e9;
    if (x == n) return ret = 0;
    ret = 1e9;
    if (y == 0) ret = min(ret, solve(x + 3, 1) + k);
    ret = min(ret, solve(x + 1, y) + a[x].first);
    ret = min(ret, solve(x + 2, y) + a[x].second);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> a[i].first >> a[i].second;
    cin >> k;

    cout << solve(1, 0);
}