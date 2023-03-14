#include <bits/stdc++.h>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 500;
int p[N * N];
int n, m;

int pos(int x, int y)
{
    return x * m + y;
}

int find(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}

int solution(vector<vector<int>> a, int h) 
{
    n = a.size(), m = a[0].size();
    for (int i = 0; i < n * m; i++) p[i] = i;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            int w = abs(a[i][j] - a[ni][nj]);
            if (w <= h)
            {
                int u = find(pos(i, j)), v = find(pos(ni, nj));
                p[u] = v;
            }
        }
    }
    
    vector<tuple<int, int, int>> edge;
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            int w = abs(a[i][j] - a[ni][nj]);
            int u = find(pos(i, j)), v = find(pos(ni, nj));
            if (u != v)
                edge.push_back({ w, u, v });
        }
    }
    
    sort(edge.begin(), edge.end());
    
    int ans = 0;
    
    for (auto to : edge)
    {
        int w = get<0>(to), u = find(get<1>(to)), v = find(get<2>(to));
        if (u == v) continue;
        ans += w;
        p[u] = v;
    }
    
    return ans;
}