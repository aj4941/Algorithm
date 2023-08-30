#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cache[120][120];
int sum = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, vector<string> &a)
{
    sum += a[x][y] - '0';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (cache[nx][ny] || a[nx][ny] == 'X') continue;
        cache[nx][ny] = true;
        dfs(nx, ny, a);
    }
}

vector<int> solution(vector<string> a) 
{
    vector<int> ans;
    n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == 'X') continue;
        if (cache[i][j]) continue;
        cache[i][j] = true;
        sum = 0; dfs(i, j, a);
        ans.push_back(sum);
    }
    
    sort(ans.begin(), ans.end());
    
    if (ans.size() == 0) ans.push_back(-1);
    return ans;
}