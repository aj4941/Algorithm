#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000;
ll dp[20][N];
int n, m;

int main(void) 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    memset(dp, 0, sizeof dp);
    cin >> n >> m;
    for (int j = 0; j <= m; j++) dp[0][j] = 1;
    for (int i = 1; i < n; i++)
    {
      for (int j = 2; j <= m; j++) 
        dp[i - 1][j] += dp[i - 1][j - 1];
      
      for (int j = 2; j <= m; j++)
        dp[i][j] = dp[i - 1][j / 2];
    }

    ll ans = 0;
    for (int j = 1; j <= m; j++)
      ans += dp[n - 1][j];

    cout << ans << "\n";
  }

  return 0;
}
