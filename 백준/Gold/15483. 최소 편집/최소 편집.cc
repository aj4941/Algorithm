#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1002;
int dp[N][N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = 1e9;
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++)
    {
        if (j - 1 >= 0)
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        if (i - 1 >= 0)
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        if (i - 1 >= 0 && j - 1 >= 0)
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
    }

    cout << dp[n][m];
}