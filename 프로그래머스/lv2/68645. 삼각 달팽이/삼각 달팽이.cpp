#include <bits/stdc++.h>
using namespace std;
int dx[3] = { 1, 0, -1 };
int dy[3] = { 0, 1, -1 };
int a[1002][1002];

vector<int> solution(int n) 
{
    int x = 0, y = 0, idx = 1, k = 0; 
    a[x][y] = idx;
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[(k + i) % 3];
            int ny = y + dy[(k + i) % 3];
            if (nx < 0 || ny < 0 || nx >= n || ny > nx) continue;
            if (a[nx][ny] != 0) continue;
            a[nx][ny] = ++idx; x = nx, y = ny;
            k = (k + i) % 3;
            flag = true;
            break;
        }
        if (!flag)
            break;
    }
    
    vector<int> ans;
    
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (a[i][j] == 0) continue;
        ans.push_back(a[i][j]);
    }
    
    return ans;
}