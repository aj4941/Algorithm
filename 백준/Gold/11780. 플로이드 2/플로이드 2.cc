#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007
const ll N = 200;
ll dist[N][N], route[N][N];
vector<ll> v;

void solve(ll x, ll y)
{
    if (route[x][y] == 0)
    {
        v.push_back(x);
        v.push_back(y);
        return;
    }
    solve(x, route[x][y]);
    v.pop_back();
    solve(route[x][y], y);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m; cin >> n >> m;

    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
        dist[i][j] = 1e18;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (dist[i][j] > dist[i][k] + dist[k][j])
            {
                dist[i][j] = dist[i][k] + dist[k][j];
                route[i][j] = k;
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (dist[i][j] == 1e18) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << "\n";
    }

    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
    {
        if (dist[i][j] == 1e18)
        {
            cout << 0 << "\n";
            continue;
        }
        v.clear(); solve(i, j);
        cout << v.size() << ' ';
        for (auto to : v) 
            cout << to << ' ';
        cout << "\n";
    }
}