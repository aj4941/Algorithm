#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
int n, k;
vector<pii> a;
bool cache[100];
int ans = 1e9;

void dfs(int idx, int cnt)
{
    if (cnt == k)
    {
        vector<pii> v1, v2;
        for (int i = 0; i < n; i++)
        {
            if (!cache[i]) v1.push_back(a[i]); // 집
            else v2.push_back(a[i]); // 대피소
        }

        int res = 0;
        for (int i = 0; i < v1.size(); i++) // 집
        {
            int tmp = 1e9;
            for (int j = 0; j < v2.size(); j++) // 대피소
                tmp = min(tmp, abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second));

            res = max(res, tmp);
        }

        ans = min(ans, res);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        cache[i] = true;
        dfs(i + 1, cnt + 1);
        cache[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a.push_back({ x, y });
    }

    dfs(0, 0);

    cout << ans;
}