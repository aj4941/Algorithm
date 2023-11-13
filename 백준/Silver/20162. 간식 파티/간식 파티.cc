#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
int a[N], n;
int dp[N][N];

int solve(int i, int mi)
{
    int &ret = dp[i][mi];
    if (ret != -1) return ret;
    if (i == n) return 0;
    ret = solve(i + 1, mi);
    if (a[mi] < a[i + 1])
        ret = max(ret, solve(i + 1, i + 1) + a[i + 1]);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << solve(0, 0);
}