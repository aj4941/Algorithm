#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100005;
int cnt[N], dp[N];
int n, m, A, B;

int solve(int v)
{
    int &ret = dp[v];
    if (ret != -1) return ret;
    if (v == n) return ret = 0;
    ret = 1e9;
    if (v + A <= n && cnt[v + A] == 0)
        ret = min(ret, solve(v + A) + 1);
    if (v + B <= n && cnt[v + B] == 0)
        ret = min(ret, solve(v + B) + 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> A >> B;
    for (int i = 0; i < m; i++)
    {
        int l, r; cin >> l >> r;
        cnt[l]++; cnt[r + 1]--;
    }

    for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];

    int ans = solve(0);
    if (ans == 1e9) ans = -1;
    cout << ans;
}