#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll dp[402][402][202];
bool cache[402][402];
int x, y, t, ex, ey, n;

ll solve(int cx, int cy, int ct)
{
    ll &ret = dp[cx][cy][ct];
    if (ret != -1) return ret;
    if (ct > t) return ret = 0;
    if ((ex - x + 200 == cx) && (ey - y + 200 == cy))
        return ret = 1;

    ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (nx < 0 || ny < 0 || nx > 400 || ny > 400) continue;
        if (cache[nx][ny]) continue;
        ret += solve(nx, ny, ct + 1) % inf;
        ret %= inf;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(cache, false, sizeof cache);
    memset(dp, -1, sizeof dp);
    cin >> x >> y >> t;
    cin >> ex >> ey;

    // cout << "res : " << ex - x << ' ' << ey - y << endl;

    if (abs(ex - x) + abs(ey - y) > 200)
    {
        cout << 0;
        return 0;
    }

    int mn_x = min(x, ex), mn_y = min(y, ey);
    x -= mn_x, y -= mn_y, ex -= mn_x, ey -= mn_y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cx, cy; cin >> cx >> cy;
        cx -= mn_x, cy -= mn_y;
        if (abs(cx - x) > 200 || abs(cy - y) > 200) continue;
        cache[cx - x + 200][cy - y + 200] = true;
    }

    cout << solve(200, 200, 0);
}
