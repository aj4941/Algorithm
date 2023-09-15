#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool cache[502][502][8];
int n, m;
vector<string> a;

struct Node {
    int x, y, c;
};

int dfs(int x, int y, int c, int len)
{
    if (cache[x][y][c])
        return len;
    
    cache[x][y][c] = true;
    
    int nx = (x + dx[c] + n) % n;
    int ny = (y + dy[c] + m) % m;
    int nc = c; 
    if (a[nx][ny] == 'L') nc = (nc + 1) % 4;
    if (a[nx][ny] == 'R') nc = (nc - 1 + 4) % 4;
    
    return dfs(nx, ny, nc, len + 1);
}

vector<int> solution(vector<string> grid) 
{
    vector<int> ans;
    a = grid;
    n = a.size(), m = a[0].size(); 
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (cache[i][j][c]) continue;
            ans.push_back(dfs(i, j, c, 0));
        }
    }

    sort(ans.begin(), ans.end());
    
    return ans;
}