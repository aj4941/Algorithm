#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 502;
int n;
int dp[N][N];

int solve(int x, int y, vi &a)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = a[x][y];
    if (x == n - 1) return ret;
    int res = max(solve(x + 1, y, a), solve(x + 1, y + 1, a));
    ret += res;
    return ret;
}

int solution(vi a) 
{
    n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            dp[i][j] = -1;
    }
    return solve(0, 0, a);
}