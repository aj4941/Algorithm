#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 200;
ll n, m, a[N];
ll ans = 0;

void dfs(int idx, ll sum, int cnt)
{
    ans = max(ans, sum);
    if (cnt == m) return;
    if (idx + 1 <= n) dfs(idx + 1, sum + a[idx + 1], cnt + 1);
    if (idx + 2 <= n) dfs(idx + 2, sum / 2 + a[idx + 2], cnt + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(0, 1, 0);

    cout << ans;
}