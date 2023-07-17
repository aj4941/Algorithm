#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int ans = 1e9;

void dfs(int i, int w, int h, vector<int> &p, vector<pii> &v)
{
    if (i == 3)
    {
        ans = min(ans, w * h);
        return;
    }
    int idx = p[i];
    for (int k = 0; k < 2; k++)
    {
        swap(v[idx].first, v[idx].second);
        int x = v[idx].first, y = v[idx].second;
        dfs(i + 1, w + x, max(h, y), p, v);
        dfs(i + 1, max(w, x), h + y, p, v);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        vector<pii> v;
        for (int i = 0; i < 3; i++)
        {
            int x, y; cin >> x >> y;
            v.push_back({ x, y });
        }
        ans = 1e9;
        vector<int> p = { 0, 1, 2 };
        do {
            dfs(0, 0, 0, p, v);
        } while (next_permutation(p.begin(), p.end()));

        cout << ans << "\n";
    }
}