#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int cnt[5];

int calc(int x1, int y1, int x2, int y2, vi &a)
{
    int num = a[x1][y1];
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (num != a[i][j])
                return 2;
        }
    }
    return num;
}

void solve(int x1, int y1, int x2, int y2, vi &a)
{
    int res = calc(x1, y1, x2, y2, a);
    if (res != 2)
    {
        cnt[res]++;
        return;
    }
    int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
    solve(x1, y1, mx, my, a);
    solve(x1, my + 1, mx, y2, a);
    solve(mx + 1, y1, x2, my, a);
    solve(mx + 1, my + 1, x2, y2, a);
}

vector<int> solution(vi a) 
{
    int n = a.size();
    solve(0, 0, n - 1, n - 1, a);
    return { cnt[0], cnt[1] };
}