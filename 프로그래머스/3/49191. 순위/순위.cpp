#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 120;
int f[N][N];

int solution(int n, vi results) 
{
    for (auto to : results)
    {
        f[to[0]][to[1]] = 1;
        f[to[1]][to[0]] = -1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (i == k || j == k) continue;
            if (f[i][k] == 1 && f[k][j] == 1) f[i][j] = 1;
            else if (f[i][k] == -1 && f[k][j] == -1) f[i][j] = -1;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (f[i][j] == 0) flag = false;
        }
        if (flag) ans++;
    }
    
    return ans;
}