#include <bits/stdc++.h>
using namespace std;
const int N = 2502;
bool dp[N][N];

int solution(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = true;
    }
    
    for (int k = 2; k < n; k++)
    {
        for (int i = 0; i + k < n; i++)
        {
            int j = i + k;
            if (dp[i + 1][j - 1] && s[i] == s[j])
                dp[i][j] = true;
        }
    }
    
    int ans = 1;
    
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i + k < n; i++)
        {
            int j = i + k;
            if (dp[i][j])
                ans = max(ans, j - i + 1);
        }
    }
    
    return ans;
}