#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int kdx[4] = { -1, -1, 1, 1 };
int kdy[4] = { -1, 1, -1, 1 };
int dist[20][20];
bool cache[20][20];
int R = 9, C = 8;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, y; cin >> x >> y;
    int kx, ky; cin >> kx >> ky; cache[kx][ky] = true;
    memset(dist, -1, sizeof dist);
    queue<pii> q; q.push({ x, y }); dist[x][y] = 0;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        if (x == kx && y == ky) break;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (dx[i] == -1 && kdx[j] != -1) continue;
                if (dx[i] == 1 && kdx[j] != 1) continue;
                if (dy[i] == -1 && kdy[j] != -1) continue;
                if (dy[i] == 1 && kdy[j] != 1) continue;
                int nx1 = x + dx[i], ny1 = y + dy[i];
                int nx2 = nx1 + kdx[j], ny2 = ny1 + kdy[j];
                int nx3 = nx2 + kdx[j], ny3 = ny2 + kdy[j];
                if (nx1 < 0 || ny1 < 0 || nx1 > R || ny1 > C) continue;
                if (nx2 < 0 || ny2 < 0 || nx2 > R || ny2 > C) continue;
                if (nx3 < 0 || ny3 < 0 || nx3 > R || ny3 > C) continue;
                if (cache[nx1][ny1] || cache[nx2][ny2] || dist[nx3][ny3] != -1) continue;
                dist[nx3][ny3] = dist[x][y] + 1;
                q.push({ nx3, ny3 });
            }
        }
    }

    cout << dist[kx][ky];
}
