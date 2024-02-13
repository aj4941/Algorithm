#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1000000007;
const ll N = 200002;
ll dp[N][15], n;
string s;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i > 0)
                dp[i][j] = dp[i - 1][j];
        }
        if (s[i] == 'W')
        {
            dp[i][0] += 1;
            dp[i][0] %= inf;
        }
        else if (s[i] == 'H')
        {
            if (i > 0)
            {
                dp[i][1] += dp[i - 1][0];
                dp[i][1] %= inf;
            }
        }
        else if (s[i] == 'E')
        {
            if (i > 0)
            {
                dp[i][2] += dp[i - 1][1]; dp[i][2] %= inf;
                dp[i][3] += dp[i - 1][2]; dp[i][3] %= inf;
                dp[i][3] += dp[i - 1][3]; dp[i][3] %= inf;
            }
        }
    }

    cout << dp[n - 1][3] % inf;
}