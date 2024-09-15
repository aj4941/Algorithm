#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
ll ans[3][3];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> org_x(3), org_y(3);
    for (int i = 0; i < 3; i++)
        cin >> org_x[i] >> org_y[i];

    for (int c = 0; c <= org_x[0]; c++)
    {
        vector<ll> x(3), y(3);
        x = org_x, y = org_y;
        memset(ans, 0, sizeof ans);
        y[1] -= c, y[2] -= (org_x[0] - c); x[0] = 0;
        if (y[1] < 0 || y[2] < 0) continue;
        ans[0][1] = c, ans[0][2] = org_x[0] - c;

        ll mn = min(x[1], y[2]);
        ans[1][2] = mn, x[1] -= mn, y[2] -= mn;

        mn = min(x[2], y[1]);
        ans[2][1] = mn, x[2] -= mn, y[1] -= mn;

        mn = min(x[1], y[0]);
        ans[1][0] = mn, x[1] -= mn, y[0] -= mn;

        mn = min(x[2], y[0]);
        ans[2][0] = mn, x[2] -= mn, y[0] -= mn;

        bool flag = true;
        for (int i = 0; i < 3; i++)
        {
            if (x[i] != 0 || y[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << 1 << "\n";
            cout << ans[0][1] << ' ' << ans[0][2] << "\n";
            cout << ans[1][0] << ' ' << ans[1][2] << "\n";
            cout << ans[2][0] << ' ' << ans[2][1] << "\n";
            return 0;
        }
    }

    cout << 0;
}