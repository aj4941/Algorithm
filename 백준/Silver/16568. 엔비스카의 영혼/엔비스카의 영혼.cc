#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1000002;
int n, a, b;
int dp[N];

int solve(int idx)
{
    int &ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == 0) return ret = 0;
    ret = solve(idx - 1) + 1;
    if ((idx - 1 - b) >= 0) ret = min(ret, solve(idx - 1 - b) + 1);
    if ((idx - 1 - a) >= 0) ret = min(ret, solve(idx - 1 - a) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> a >> b;

    cout << solve(n);
}