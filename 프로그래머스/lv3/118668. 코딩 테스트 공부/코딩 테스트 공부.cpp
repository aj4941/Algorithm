#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 152;
int dp[N][N];
int mx_a, mx_b;

int solve(int a, int b, vi &p)
{
    if (a == mx_a && b == mx_b) return 0;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    ret = 1e9;
    if (a < mx_a) ret = min(ret, solve(a + 1, b, p) + 1);
    if (b < mx_b) ret = min(ret, solve(a, b + 1, p) + 1);
    
    for (auto to : p)
    {
        int ra = to[0], rb = to[1], ga = to[2], gb = to[3], t = to[4];
        if (a >= ra && b >= rb)
            ret = min(ret, solve(min(mx_a, a + ga), min(mx_b, b + gb), p) + t);
    }
    
    return ret;
}

int solution(int alp, int cop, vi p)
{
    memset(dp, -1, sizeof dp);

    for (auto to : p)
    {
        int a = to[0], b = to[1];
        mx_a = max(mx_a, a), mx_b = max(mx_b, b);
    }
    
    return solve(alp, cop, p);
    
    // cout << mx_a << ' ' << mx_b << endl;
    // 약간 넘어갈 수도 있고 그 값이 최적일수도 있음
    // int ans = 1e9;
    
    // for (int i = mx_a; i < 500; i++) for (int j = mx_b; j < 500; j++)
        // ans = min(ans, solve(i, j, p));
    
    // return ans;
}