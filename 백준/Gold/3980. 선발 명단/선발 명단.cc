#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int dp[N][1 << N];
int a[N][N];
const int MAX = (1 << 11) - 1;
// 2^0 + 2^1 ... + 2^10

int solve(int x, int bit)
{
    if (x == 11)
    {
        if (bit == MAX) return 0;
        else return -1e9;
    }
    int& ret = dp[x][bit];
    if (ret != -1) return ret;
    ret = -1e9;
    for (int i = 0; i < 11; i++)
    {
        if (bit & (1 << i)) continue;
        if (a[x][i] == 0) continue;
        ret = max(ret, solve(x + 1, bit | (1 << i)) + a[x][i]);
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
                cin >> a[i][j];
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << "\n";
    }
}