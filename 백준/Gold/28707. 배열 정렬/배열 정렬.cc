#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 10;
map<vector<int>, int> dist;
int n, m;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    dist[a] = 0;
    cin >> m;
    vector<pair<pii, int>> p;
    for (int i = 0; i < m; i++)
    {
        int l, r, c; cin >> l >> r >> c;
        p.push_back({ { l - 1, r - 1 }, c });
    }

    priority_queue<pair<int, vector<int>>> pq;
    pq.push({ 0, a });

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        int d = -to.first;
        vector<int> cur = to.second;
        if (dist[cur] != d) continue;
        for (int i = 0; i < m; i++)
        {
            int c = p[i].second;
            int l = p[i].first.first, r = p[i].first.second;
            swap(cur[l], cur[r]);
            if (!dist.count(cur) || d + c < dist[cur])
            {
                dist[cur] = d + c;
                pq.push({ -dist[cur], cur });
            }
            swap(cur[l], cur[r]);
        }
    }

    sort(a.begin(), a.end());

    if (!dist.count(a)) cout << -1;
    else cout << dist[a];
}