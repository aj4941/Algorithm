#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
ll dp[202][202][102];
int h, w, l;
string s[202];
string f;

ll solve(int x, int y, int len)
{
    ll &ret = dp[x][y][len];
    if (ret != -1) return ret;
    if (len == f.size()) return ret = 1;
    ret = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (f[len] == s[nx][ny])
            ret += solve(nx, ny, len + 1);
    }
    return ret;
}

int main(void)
{
    memset(dp, -1, sizeof dp);
    cin >> h >> w >> l;
    for (int i = 0; i < h; i++) cin >> s[i];
    cin >> f;

    ll ans = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        if (f[0] == s[i][j])
        {
            ans += solve(i, j, 1);
        }
    }

    cout << ans;
    return 0;
}