#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 100002;
int dp[N][12][12];
pii pos[12] = { { 3, 1 }, { 0, 0 }, { 0, 1 },
               { 0, 2 }, { 1, 0 }, { 1, 1 },
               { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2, 2 } };

int calc(pii pos1, pii pos2)
{
    int x1 = pos1.first, y1 = pos1.second;
    int x2 = pos2.first, y2 = pos2.second;
    int dx = abs(x1 - x2), dy = abs(y1 - y2);
    int mn = min(dx, dy);
    int res = mn * 3; dx -= mn, dy -= mn;
    res += 2 * dx + 2 * dy; 
    return res;
}

int solve(int idx, int x, int y, string &s)
{
    int &ret = dp[idx][x][y];
    if (ret != -1) return ret;
    if (idx == s.size()) return ret = 0;
    ret = 1e9;
    int nv = s[idx] - '0';
    if (x == nv || y == nv)
        return ret = solve(idx + 1, x, y, s) + 1;
    
    int r1 = calc(pos[x], pos[nv]);
    int r2 = calc(pos[y], pos[nv]);
    
    ret = min(ret, solve(idx + 1, nv, y, s) + r1);
    ret = min(ret, solve(idx + 1, x, nv, s) + r2);
    return ret;
}

int solution(string s) 
{
    memset(dp, -1, sizeof dp);
    return solve(0, 4, 6, s);
}