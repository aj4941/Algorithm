#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int N = 200002;
int dp[N], a[N];
int n;

int solve(int idx)
{
    if (idx >= n) return 0;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    return ret = solve(idx + a[idx] + 1) + 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << solve(i) << ' ';
}