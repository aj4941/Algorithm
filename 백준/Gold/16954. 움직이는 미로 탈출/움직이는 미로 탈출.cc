#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
const int N = 100002;
int dx[9] = { -1, 1, 0, 0, -1, -1, 1, 1, 0 };
int dy[9] = { 0, 0, -1, 1, 1, -1, 1, -1, 0 };
int dist[10][10][1000];
string s[10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < 8; i++) cin >> s[i];

    queue<tii> q; q.push({ 7, 0, 0 });
    dist[7][0][0] = 1;

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = get<0>(to), y = get<1>(to), d = get<2>(to);
        for (int k = 0; k < 9; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
            if (nx - d >= 0 && s[nx - d][ny] == '#') continue;
            if (nx - (d + 1) >= 0 && s[nx - (d + 1)][ny] == '#') continue;
            if (d + 1 >= 1000) continue;
            if (dist[nx][ny][d + 1] == 1) continue;
            dist[nx][ny][d + 1] = 1;
            q.push({ nx, ny, d + 1 });
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        if (dist[0][7][i] == 1)
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}