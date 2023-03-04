#include <bits/stdc++.h>
using namespace std;
int f[120][120];

int solution(int n, vector<vector<int>> r) 
{
    for (int i = 0; i < r.size(); i++)
    {
        int x = r[i][0], y = r[i][1];
        f[x][y] = 1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (f[i][k] && f[k][j])
                f[i][j] = 1;
        }
    }
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            cnt += f[i][j] + f[j][i];
        
        if (cnt == n - 1)
            ans++;
    }
    
    return ans;
}