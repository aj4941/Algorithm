#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<pair<pii, pii>, int> idx;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a.push_back({ x, y });
    }

    vector<pair<pii, pii>> pos;

    for (int i = 1; i < n; i++)
    {
        int x1 = a[i - 1].first, y1 = a[i - 1].second;
        int x2 = a[i].first, y2 = a[i].second;
        if (y1 != y2) continue;
        pos.push_back({ { x1, y1 }, { x2, y2 } });
        idx[{ { x1, y1 }, { x2, y2 } }] = (int)pos.size() - 1;
    }

    ll ans = 0;
    vector<int> h(pos.size());
    for (auto to : pos)
    {
        int x1 = to.first.first, y1 = to.first.second;
        int x2 = to.second.first, y2 = to.second.second;
        ans += y1 * (x2 - x1);
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int cur = idx[{ { x1, y1 }, { x2, y2 }}];
        h[cur] = max(h[cur], y1);
        for (int j = cur - 1; j >= 0; j--)
            h[j] = max(h[j], min(h[j + 1], pos[j].second.second));
        for (int j = cur + 1; j < pos.size(); j++)
            h[j] = max(h[j], min(h[j - 1], pos[j].second.second));
    }

    for (int i = 0; i < pos.size(); i++)
    {
        int x1 = pos[i].first.first, y1 = pos[i].first.second;
        int x2 = pos[i].second.first, y2 = pos[i].second.second;
        ans -= h[i] * (x2 - x1);
    }

    cout << ans;
}