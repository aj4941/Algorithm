#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 10002;
int dp[5][N];
ll x, a[4];
ll c[4] = { 1, 5, 10, 25 };

int solve(int idx, int cost)
{
    int &ret = dp[idx][cost];
    if (ret != -1) return ret;
    ret = -1e9;

    if (idx == 4)
        return ret = (cost == x) ? 0 : -1e9;

    for (int i = 0; i <= a[idx]; i++)
    {
        int ncost = cost + c[idx] * i;
        if (ncost <= x)
            ret = max(ret, solve(idx + 1, ncost) + i);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> x;
    for (int i = 0; i < 4; i++) cin >> a[i];

    memset(dp, -1, sizeof dp);

    int res = solve(0, 0);

    if (res < 0)
    {
        cout << "0 0 0 0";
        return 0;
    }

    vector<int> ans;
    int idx = 0, cost = 0;

    while (idx < 4)
    {
        for (int i = 0; i <= a[idx]; i++)
        {
            int ncost = cost + c[idx] * i;
            if (ncost <= x && dp[idx][cost] == dp[idx + 1][ncost] + i)
            {
                ans.push_back(i);
                idx = idx + 1, cost = ncost;
                break;
            }
        }
    }

    for (auto to : ans)
        cout << to << ' ';
}