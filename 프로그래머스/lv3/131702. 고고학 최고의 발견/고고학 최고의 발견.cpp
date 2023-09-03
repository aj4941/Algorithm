#include <bits/stdc++.h>
using namespace std;
const int N = 10;
typedef vector<vector<int>> vi;
int n, m;
int prv[N];
int dx[5] = { -1, 1, 0, 0, 0 };
int dy[5] = { 0, 0, -1, 1, 0 };
int ans = 1e9;

void calc(int x, int y, int k, vi &sa)
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        sa[nx][ny] = (sa[nx][ny] + k) % 4;
    }
}

void dfs(int j, vi &a)
{
    if (j == m)
    {
        int res = 0;
        vi sa = a;
        for (int j = 0; j < m; j++)
        {
            calc(0, j, prv[j], sa);
            res += prv[j];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int rm = (4 - sa[i - 1][j]) % 4;
                calc(i, j, rm, sa);
                res += rm;
            }
        }
        
        bool hasAns = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (sa[i][j] != 0)
                    hasAns = false;
            }
        }
        
        if (hasAns)
            ans = min(ans, res);
        
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        prv[j] = i;
        dfs(j + 1, a);
    }
}

int solution(vi a)
{
    n = a.size(), m = a[0].size();
    dfs(0, a);
    return ans;
}