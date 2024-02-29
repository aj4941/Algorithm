#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int n, m;

int solution(vi a)
{
    n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == 0) continue;
        if (i == 0 || j == 0)
        {
            if (a[i][j] == 1)
                dp[i][j] = 1;
        }
        else
        {
            int r1 = dp[i - 1][j - 1];
            int r2 = dp[i - 1][j];
            int r3 = dp[i][j - 1];
            dp[i][j] = min(r1, min(r2, r3)) + 1;
        }
        
        ans = max(ans, dp[i][j]);
    }
    
    return ans * ans;
}