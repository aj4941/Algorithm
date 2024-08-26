#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 102;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool cache[N][N];
ll dp[N][N];
int n, m, a, b;
vector<pii> v;

ll solve(int x, int y, int ex, int ey)
{
    ll &ret = dp[x][y];
    if (ret != -1) return ret;
    if (x > ex || y > ey) return ret = 0;
    if (x == ex && y == ey) return ret = 1;
    ret = 0;
    if (!cache[x + 1][y])
        ret += solve(x + 1, y, ex, ey);
    if (!cache[x][y + 1])
        ret += solve(x, y + 1, ex, ey);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;

    v.push_back({ 1, 1 });

    for (int i = 0; i < a; i++)
    {
        int x, y; cin >> x >> y;
        v.push_back({ x, y });
    }

    v.push_back({ n, m });

    sort(v.begin(), v.end());

    for (int i = 0; i < b; i++)
    {
        int x, y; cin >> x >> y;
        cache[x][y] = true;
    }

    ll ans = 1;

    for (int i = 0; i < (int)v.size() - 1; i++)
    {
        memset(dp, -1, sizeof dp);
        pii st = v[i], ed = v[i + 1];
        ans *= solve(st.first, st.second, ed.first, ed.second);
    }

    cout << ans;
}