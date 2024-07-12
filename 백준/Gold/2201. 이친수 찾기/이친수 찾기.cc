#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 1000;
ll cnt[N], dp[N][2];
ll len;

ll solve(int idx, int c)
{
    ll &ret = dp[idx][c];
    if (ret != -1) return ret;
    if (idx == len) return ret = 1;

    if (c == 0)
        return ret = solve(idx + 1, 0) + solve(idx + 1, 1);
    else
        return ret = solve(idx + 1, 0);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cnt[1] = cnt[2] = 1;
    for (int i = 3; i < N; i++)
    {
        if (cnt[i - 1] > 1e18 - cnt[i - 2]) break;
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    }

    ll k; cin >> k;

    for (int i = 1; i < N; i++)
    {
        if (k - cnt[i] > 0) k -= cnt[i];
        else
        {
            len = i;
            break;
        }
    }

    memset(dp, -1, sizeof dp);

    solve(1, 1);

    int idx = 1, c = 1;

    while (true)
    {
        cout << c;

        if (idx == len)
            return 0;

        if (c == 0)
        {
            if (k <= dp[idx + 1][0])
                idx++, c = 0;
            else
            {
                k -= dp[idx + 1][0];
                idx++, c = 1;
            }
        }
        else
            idx++, c = 0;
    }
}