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
pii even[6] = { { -1, -1 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 1 }, { -1, 0 } };
pii odd[6] = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 0 } };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200;
int a[N][N];
bool cache[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int w, h; cin >> w >> h; // 8 4
    for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++)
        cin >> a[j][i]; // (j, i)

    ll ans = 0;
    // (j, i)
    queue<pii> q;
    for (int i = 0; i <= h + 1; i++) for (int j = 0; j <= w + 1; j++)
    {
        if (i <= 1 || j <= 1 || i >= h || j >= w)
        {
            if (a[j][i] == 0)
            {
                q.push({ j, i });
                cache[j][i] = true;
            }
        }
    }

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int j = to.first, i = to.second;

        for (int k = 0; k < 6; k++)
        {
            int nj = j, ni = i;
            if (i % 2) nj += odd[k].first, ni += odd[k].second;
            else nj += even[k].first, ni += even[k].second;

            if (ni < 0 || nj < 0 || ni > h + 1 || nj > w + 1) continue;

            if (a[nj][ni])
                ans++;

            if (!cache[nj][ni] && a[nj][ni] == 0)
            {
                q.push({ nj, ni });
                cache[nj][ni] = true;
            }
        }
    }

    cout << ans;
}