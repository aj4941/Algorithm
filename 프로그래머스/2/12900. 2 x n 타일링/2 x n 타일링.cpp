#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 70002;
const ll inf = 1000000007;
ll dp[N];

int solution(int n) 
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= inf;
    }
    
    return dp[n];
}