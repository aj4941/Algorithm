#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 10002;
int dp[N][N / 10];
int n, m;
bool cache[N];

int solve(int pos, int x)
{
    if (pos > n) return 1e9;
    int &ret = dp[pos][x];
    if (ret != -1) return ret;
    ret = 1e9;
    if (cache[pos]) return ret;
    if (pos == n) return ret = 0;
    if (x - 1 >= 1) ret = min(ret, solve(pos + (x - 1), x - 1) + 1);
    ret = min(ret, solve(pos + x, x) + 1);
    ret = min(ret, solve(pos + (x + 1), x + 1) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        cache[x] = true;
    }

    if (cache[2])
    {
        cout << -1;
        return 0;
    }

    int ans = solve(2, 1) + 1;
    if (ans >= 1e9) ans = -1;
    cout << ans;
}