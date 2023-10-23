#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 100002;
int dp[N][5];
int a[N][5];

int solution(vi land)
{
    int ans = 0;
    int n = land.size(), m = land[0].size();
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = land[0][j];
        ans = max(ans, dp[0][j]);
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    
    return ans;
}