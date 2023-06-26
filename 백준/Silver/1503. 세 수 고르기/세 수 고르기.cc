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
const int N = 2002;
bool cache[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        cache[x] = true;
    }

    int ans = 1e9;

    for (int i = 1; i <= 1100; i++)
    {
        if (cache[i]) continue;
        for (int j = i; j <= 1100; j++)
        {
            if (cache[j]) continue;
            for (int k = j; k <= 1100; k++)
            {
                if (cache[k]) continue;
                ans = min(ans, abs(n - i * j * k));
            }

        }
    }

    cout << ans;
}