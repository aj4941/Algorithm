#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 100002;
vector<pll> v[N];
priority_queue<pll> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, C; cin >> n >> C;
    for (ll i = 0; i < n; i++)
    {
        ll x, y, k; cin >> x >> y >> k;
        v[x].push_back({ y, k });
    }

    ll max_y = 1e5;
    ll ans = 0, res = 0;
    
    for (ll x = 0; x <= 1e5; x++) 
    {
        if (v[x].size() == 0) continue;
        for (pll to : v[x])
        {
            if (to.first <= max_y)
            {
                pq.push({ to.first, -to.second });
                res += to.second;
            }
        }

        while (pq.size() > C)
        {
            res -= -pq.top().second; pq.pop();
            max_y = pq.top().first;
        }

        ans = max(ans, res);
    }

    cout << ans;
}