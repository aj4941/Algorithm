#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 10;
vector<pll> a;
int n;
ll ans = 0;

void dfs(int i, vector<pll>& a, ll cnt)
{
    ans = max(ans, cnt);

    if (i == n)
        return;

    if (a[i].first <= 0)
    {
        dfs(i + 1, a, cnt);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (i == j) continue;
        ll cur_cnt = 0;
        pll &x = a[i], &y = a[j];
        if (y.first <= 0) continue;
        ll xw = x.second, yw = y.second;
        x.first -= yw, y.first -= xw;
        if (x.first <= 0) cur_cnt++;
        if (y.first <= 0) cur_cnt++;
        dfs(i + 1, a, cnt + cur_cnt);
        x.first += yw, y.first += xw;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        a.push_back({ x, y });
    }

    dfs(0, a, 0);
    cout << ans;
}