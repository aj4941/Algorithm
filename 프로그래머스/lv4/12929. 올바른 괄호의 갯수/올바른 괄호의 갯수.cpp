#include <bits/stdc++.h> 
using namespace std;
const int S = 50;
int dp[S][S];
int N;

int solve(int idx, int sum)
{
    int &ret = dp[idx][sum];
    if (ret != -1) return ret;
    if (idx == N * 2)
    {
        if (sum == S)
            return ret = 1;
        else
            return ret = 0;
    }
    
    ret = 0;
    ret += solve(idx + 1, sum + 1);
    if (sum - 1 >= S) ret += solve(idx + 1, sum - 1);
    return ret;
}

int solution(int n) {
    N = n;
    memset(dp, -1, sizeof dp);
    return solve(0, S);
}