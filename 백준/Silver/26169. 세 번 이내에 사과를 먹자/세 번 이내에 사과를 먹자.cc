#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10];
bool cache[10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool hasAns = false;

void dfs(int x, int y, int cnt, int rm)
{
    if (rm == 0)
    {
        if (cnt >= 2)
        {
            // cout << x << ' ' << y << ' ' << cnt << endl;
            hasAns = true;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (cache[nx][ny] || a[nx][ny] == -1) continue;
        cache[x][y] = true;
        if (a[nx][ny] == 1)
            dfs(nx, ny, cnt + 1, rm - 1);
        else
            dfs(nx, ny, cnt, rm - 1);
        cache[x][y] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        cin >> a[i][j];

    int x, y; cin >> x >> y;
    dfs(x, y, 0, 3);

    if (hasAns) cout << 1;
    else cout << 0;
}