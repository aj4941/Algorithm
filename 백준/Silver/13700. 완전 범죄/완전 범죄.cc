#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 500002;
int cache[N], dist[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s, d, f, b, k;
    cin >> n >> s >> d >> f >> b >> k;
    for (int i = 0; i < k; i++)
    {
        int x; cin >> x;
        cache[x] = true;
    }

    memset(dist, -1, sizeof dist); dist[s] = 0;
    queue<int> q; q.push(s);

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (!cache[v + f] && dist[v + f] == -1)
        {
            dist[v + f] = dist[v] + 1;
            q.push(v + f);
        }
        if (!cache[v - b] && v - b >= 0 && dist[v - b] == -1)
        {
            dist[v - b] = dist[v] + 1;
            q.push(v - b);
        }
    }

    int ans = dist[d];
    if (ans == -1)
    {
        cout << "BUG FOUND";
        return 0;
    }
    
    cout << dist[d];
}