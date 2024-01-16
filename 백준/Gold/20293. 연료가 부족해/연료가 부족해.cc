#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, t;
int dp[2002];
vector<pair<pii, int>> v;

int solve(int idx)
{
    int &ret = dp[idx];
    if (ret != -1) return ret;
    int x = v[idx].first.first, y = v[idx].first.second, f = v[idx].second;
    ret = -1e9;

    for (int i = 0; i < v.size(); i++)
    {
        if (i == idx) continue;
        int nx = v[i].first.first, ny = v[i].first.second;
        if (x < nx || y < ny) continue;
        int dist = abs(x - nx) + abs(y - ny);
        int dpValue = solve(i);
        if (dpValue - dist >= 0)
            ret = max(ret, dpValue - dist + f);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    v.push_back({ { 1, 1 }, 0 });
    for (int i = 0; i < t; i++)
    {
        int x, y, f; cin >> x >> y >> f;
        v.push_back({ { x, y }, f });
    }
    v.push_back({ { n, m }, 0 });

    int l = -1, r = 1e9;
    while (l + 1 < r) // (l, r]
    {
        memset(dp, -1, sizeof dp);
        int mid = (l + r) / 2;
        dp[0] = mid;
        int res = solve(v.size() - 1);

        if (res == -1e9) l = mid;
        else r = mid;
    }

    cout << r;
}
