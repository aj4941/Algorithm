#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 300002;
vector<int> pos, pos_h;
vector<pii> vec[N];
int p[N];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < N; i++) p[i] = i;
    int n, m; cin >> n >> m;
    vector<pair<int, pii>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y, h; cin >> x >> y >> h;
        v.push_back({ h, { x, y }});
        pos.push_back(x); pos.push_back(y);
        pos_h.push_back(h);
    }

    sort(pos.begin(), pos.end());
    sort(pos_h.begin(), pos_h.end());

    for (int i = 0; i < n; i++)
    {
        auto to = v[i];
        int h = to.first, x = to.second.first, y = to.second.second;
        x = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
        y = lower_bound(pos.begin(), pos.end(), y) - pos.begin();
        h = lower_bound(pos_h.begin(), pos_h.end(), h) - pos_h.begin();
        for (int k = x; k <= y; k++)
            vec[k].push_back({ h, i + 1 });
    }

    for (int i = 0; i < N; i++)
        sort(vec[i].begin(), vec[i].end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < vec[i].size(); j++)
        {
            int u = vec[i][j].second, v = vec[i][j - 1].second;
            u = find(u), v = find(v);
            p[u] = v;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        if (find(x) == find(y)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}