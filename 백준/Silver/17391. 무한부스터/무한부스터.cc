#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 400;
int dist[N][N], a[N][N];
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dist, -1, sizeof dist);
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    queue<pii> q; q.push({ 0, 0 });
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int k = 0; k < 2; k++)
        {
            for (int d = 1; d <= a[x][y]; d++)
            {
                int nx = x + dx[k] * d, ny = y + dy[k] * d;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    cout << dist[n - 1][m - 1];
}