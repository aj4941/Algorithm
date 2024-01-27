#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200002;
vector<pll> v[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, c; cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        ll x, y, val; cin >> x >> y >> val;
        v[x].push_back({ y, val });
    }

    int y = 1e5;
    priority_queue<pll> pq;
    ll ans = 0, res = 0;

    for (int x = 0; x <= 1e5; x++)
    {
        for (auto to : v[x])
        {
            ll yi = to.first, val = to.second;
            if (y < yi) continue;
            res += val; pq.push({ yi, -val });
        }
        while (pq.size() > c)
        {
            ll yi = pq.top().first, val = -pq.top().second; pq.pop();
            y = yi; res -= val;
        }

        while (pq.size())
        {
            ll yi = pq.top().first, val = -pq.top().second;
            if (y <= yi)
            {
                res -= val;
                pq.pop();
            }
            else
                break;
        }

        ans = max(ans, res);
    }

    cout << ans;
}