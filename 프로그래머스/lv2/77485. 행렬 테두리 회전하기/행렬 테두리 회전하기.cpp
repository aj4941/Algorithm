#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int a[200][200];

int calc(int x1, int y1, int x2, int y2)
{
    int mn = a[x1][y1];
    int tmp = a[x1][y1];
    for (int i = x1 + 1; i <= x2; i++)
    {
        a[i - 1][y1] = a[i][y1];
        mn = min(mn, a[i - 1][y1]);
    }
    for (int j = y1 + 1; j <= y2; j++)
    {
        a[x2][j - 1] = a[x2][j];
        mn = min(mn, a[x2][j - 1]);
    }
    for (int i = x2 - 1; i >= x1; i--)
    {
        a[i + 1][y2] = a[i][y2];
        mn = min(mn, a[i + 1][y2]);
    }
    for (int j = y2 - 1; j >= y1 + 1; j--)
    {
        a[x1][j + 1] = a[x1][j];
        mn = min(mn, a[x1][j + 1]);
    }
    
    a[x1][y1 + 1] = tmp;
    mn = min(mn, a[x1][y1 + 1]);
    return mn;
}

vector<int> solution(int rows, int columns, vi queries) 
{
    int val = 1;
    for (int i = 1; i <= rows; i++) for (int j = 1; j <= columns; j++)
        a[i][j] = val++;
    
    vector<int> ans;
    
    for (auto to : queries)
    {
        int x1 = to[0], y1 = to[1], x2 = to[2], y2 = to[3];
        ans.push_back(calc(x1, y1, x2, y2));
    }
    
    return ans;
}
