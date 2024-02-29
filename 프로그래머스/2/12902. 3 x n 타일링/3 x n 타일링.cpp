#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1000000007;
ll dp[10000];

int solution(int n) 
{
    if (n % 2) return 0;
    int ans = 0;
    dp[0] = 1; dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
            dp[i] %= inf;
        }
    }
    
    return dp[n];
}