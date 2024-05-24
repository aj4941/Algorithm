#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const ll N = 5002;
const ll inf = 1000000007;
ll dp[N][N], x;

ll solve(int idx, int cnt)
{
    ll &ret = dp[idx][cnt];
    if (ret != -1) return ret;
    if (idx == 0)
    {
        if (cnt == 0) return ret = 1;
        else return ret = 0;
    }
    ret = 0;
    ret += solve(idx - 1, cnt + 1); ret %= inf;
    if (cnt > 0)
        ret += solve(idx - 1, cnt - 1), ret %= inf;

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << solve(x, 0) << "\n";
    }
}