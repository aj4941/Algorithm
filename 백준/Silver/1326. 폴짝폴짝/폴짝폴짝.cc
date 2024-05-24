#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const int N = 20000;
int n;
ll dist[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof dist);
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int st, ed; cin >> st >> ed;

    queue<ll> q; q.push(st); dist[st] = 0;

    while (!q.empty())
    {
        ll x = q.front(); q.pop();
        ll k = a[x], lx = x, rx = x;
        while (true)
        {
            lx -= k;
            if (lx <= 0) break;
            if (dist[lx] == -1)
            {
                dist[lx] = dist[x] + 1;
                q.push(lx);
            }
        }
        while (true)
        {
            rx += k;
            if (rx > n) break;
            if (dist[rx] == -1)
            {
                dist[rx] = dist[x] + 1;
                q.push(rx);
            }
        }
    }

    cout << dist[ed];
}