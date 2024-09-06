#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 2002;
ll dp[N][N];
vector<ll> a;
int n;

ll solve(int x, int y)
{
    ll &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;
    ll d = a[y] - a[x];
    ll idx = lower_bound(a.begin() + y + 1, a.end(), a[y] + d) - a.begin();
    if (idx < a.size() && a[idx] == a[y] + d)
        ret = max(ret, solve(y, idx) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n; a.resize(n);
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
        ans = max(ans, solve(i, j) + 2);

    cout << ans;
}