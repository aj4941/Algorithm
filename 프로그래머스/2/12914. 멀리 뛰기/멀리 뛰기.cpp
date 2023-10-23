#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2002;
const ll inf = 1234567;
ll dp[N];

ll solution(int n) 
{
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] += dp[i - 1];
        if (i - 2 >= 0) dp[i] += dp[i - 2];
        dp[i] %= inf;
    }
    return dp[n];
}