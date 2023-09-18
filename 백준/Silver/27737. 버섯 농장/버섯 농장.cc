#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll N = 200;
ll a[N][N];
bool cache[N][N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    vector<ll> res;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (cache[i][j] || a[i][j] == 1) continue;
        int cnt = 1;
        queue<pll> q; q.push({ i, j }); cache[i][j] = true;
        while (!q.empty())
        {
            auto to = q.front(); q.pop();
            int x = to.first, y = to.second;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (a[nx][ny] == 1 || cache[nx][ny]) continue;
                cnt++; cache[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
        res.push_back(cnt);
    }

    ll need = 0;
    for (auto to : res)
        need += (to + k - 1) / k;
    
    if (need == 0)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    
    ll ans = m - need;
    if (ans < 0) cout << "IMPOSSIBLE" << "\n";
    else
    {
        cout << "POSSIBLE" << "\n";
        cout << ans << "\n";
    }

}