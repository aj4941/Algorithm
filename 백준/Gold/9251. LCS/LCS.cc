#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1002;
string s, t;
int dp[N][N];
int n, m;

int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;
    if (x == n && y == m) return ret;
    if (y < m) ret = max(ret, solve(x, y + 1));
    if (x < n) ret = max(ret, solve(x + 1, y));
    if (x < n && y < m && s[x] == t[y])
        ret = max(ret, solve(x + 1, y + 1) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
}