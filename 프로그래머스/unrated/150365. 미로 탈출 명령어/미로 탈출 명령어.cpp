#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int dp[N][N][N * N];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
char ch[4] = { 'd', 'l', 'r', 'u' };

void solve(int x, int y, int k, int n, int m)
{
    // cout << x << ' ' << y << ' ' << k << endl;
    int &ret = dp[x][y][k];
    if (ret != -1) return;
    ret = 1;
    if (k == 0) return;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        solve(nx, ny, k - 1, n, m);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    memset(dp, -1, sizeof dp);
    solve(r, c, k, n, m);
    string ans = "";
    
    int sk = 0;
    
    // cout << dp[x][y][0] << endl;
    
    if (dp[x][y][0] != 1)
        return "impossible";
    
    while (sk < k)
    {
        // cout << x << ' ' << y << ' ' << sk << endl;
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx <= 0 || nx > n || ny > m) continue;
            if (dp[nx][ny][sk + 1] == 1)
            {
                ans += ch[i];
                x = nx, y = ny, sk++;
                flag = true;
                break;
            }
        }
        if (!flag)
            return "impossible";
    }
    
    return ans; 
}