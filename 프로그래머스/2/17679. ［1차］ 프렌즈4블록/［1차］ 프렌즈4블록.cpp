#include <bits/stdc++.h>
using namespace std;
const int N = 50;
bool cache[N][N];

void calc(int x, int y, vector<string> &a)
{
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x + 1][y] && a[x][y] == a[x + 1][y + 1])
        cache[x][y] = cache[x][y + 1] = cache[x + 1][y] = cache[x + 1][y + 1] = true;
}

int solution(int n, int m, vector<string> a) 
{
    while (true)
    {
        bool flag = false;
        memset(cache, false, sizeof cache);
        for (int i = 0; i < n - 1; i++) for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j] == '?') continue;
            calc(i, j, a);
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        {
            if (cache[i][j])
            {
                a[i][j] = '?';
                flag = true;
            }
        }
        
        for (int k = 0; k < n; k++) 
        {
            for (int i = n - 2; i >= 0; i--) for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '?') continue;
                if (a[i + 1][j] == '?')
                {   
                    a[i + 1][j] = a[i][j];
                    a[i][j] = '?';
                }
            }
        }
        
        if (!flag)
            break;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == '?')
            ans++;
    }
    
    return ans;
}