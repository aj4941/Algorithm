#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1002;
int dist[N][N];
bool fail[N][N];
int ex, ey, n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> ex >> ey >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        x += 500, y += 500; fail[x][y] = true;
    }

    memset(dist, -1, sizeof dist);
    queue<pii> q; q.push({ 500, 500 }); dist[500][500] = 0;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        if (x == ex + 500 && y == ey + 500) break;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 1000 || ny >= 1000) continue;
            if (fail[nx][ny] || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    cout << dist[ex + 500][ey + 500];
}