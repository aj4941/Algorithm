#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int N = 1002;
int dp[N][N];

int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 1e9;
    if (x == y) return ret = 0;
    if (x + x <= y + 3)
        ret = min(ret, solve(x + x, y + 3) + 1);
    if (x + 1 <= y)
        ret = min(ret, solve(x + 1, y) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
}