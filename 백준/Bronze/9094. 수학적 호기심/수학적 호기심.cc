#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int a = 1; a < n; a++) for (int b = a + 1; b < n; b++)
    {
        int res = a * a + b * b + m;
        if (res % (a * b)) continue;
        ans++;
    }

    cout << ans << "\n";
  }
}