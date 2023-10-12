#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 110;
int pos[3][N][N];
int n;

bool calc(int a, int x, int y)
{
    if (pos[a][x][y] == 0)
        return true;
    
    if (a == 0)
    {
        if (y == 0 || pos[1][x][y] || (x - 1 >= 0 && pos[1][x - 1][y])
            || (y - 1 >= 0 && pos[0][x][y - 1]))
            return true;
        return false;
    }
    else
    {
        if ((y - 1 >= 0 && pos[0][x][y - 1]) || 
            (x + 1 < N && y - 1 >= 0 && pos[0][x + 1][y - 1]) || 
            ((x - 1 >= 0 && pos[1][x - 1][y]) && (x + 1 < N && pos[1][x + 1][y])))
            return true;
        return false;
    }
}

vi solution(int sz, vi tmp) 
{
    n = sz;
    for (auto to : tmp)
    {
        int x = to[0], y = to[1], a = to[2], b = to[3];
        if (b == 1)
        {
            pos[a][x][y] = 1;
            if (!calc(a, x, y))
                pos[a][x][y] = 0;
        }
        else
        {
            pos[a][x][y] = 0;
            bool flag = true;
            for (int i = x - 1; i <= x + 1; i++) 
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    for (int sa = 0; sa <= 1; sa++) 
                    {
                        if (i < 0 || j < 0 || i > n || j > n) continue;
                        if (pos[sa][i][j] == 0) continue;
                        if (sa == a && i == x && j == y) continue;
                        if (!calc(sa, i, j))
                            flag = false;
                    }
                }
            }
            if (!flag)
                pos[a][x][y] = 1;
        }
    }
    
    vi ans;
    
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
    {
        for (int a = 0; a <= 1; a++)
        {
            if (pos[a][i][j])
                ans.push_back({ i, j, a });
        }
    }
    
    return ans;
}