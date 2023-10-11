#include <bits/stdc++.h> 
using namespace std;
typedef vector<vector<int>> vi;
int n, m;

void move(vi &key)
{
    vi nkey = key;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++)
        nkey[j][m - 1 - i] = key[i][j];
    
    key = nkey;
}

bool check(vi lock)
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (lock[i][j] != 1)
            return false;
    }
    return true;
}

bool solution(vi key, vi lock) 
{
    bool hasAns = false;
    n = lock.size(), m = key.size();
    for (int t = 0; t < 4; t++) 
    {
        move(key);
        for (int cx = -n - 1; cx <= n - 1; cx++) for (int cy = -n - 1; cy <= n - 1; cy++)
        {
            vi l = lock;
            for (int i = 0; i < m; i++) for (int j = 0; j < m; j++)
            {   
                int x = cx + i, y = cy + j;
                if (x < 0 || y < 0 || x >= n || y >= n) continue;
                l[x][y] += key[i][j];
            }
            
            if (check(l))
                return true;
        }
    }
    
    return false;
}