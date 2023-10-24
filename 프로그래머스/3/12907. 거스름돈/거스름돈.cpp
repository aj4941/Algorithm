#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1000000007;
const int N = 100002;
ll dp[N];

int solution(int n, vector<int> a) 
{
    dp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = a[i]; j <= n; j++)
        {
            dp[j] += dp[j - a[i]];
            dp[j] %= inf;
        }
    }
    
    return dp[n];
}