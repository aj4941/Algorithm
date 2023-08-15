#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mpow(ll a, ll x)
{
  if (x == 0)
    return 1;
  ll res = mpow(a, x / 2);
  res = res * res;
  if (x % 2) res = res * a;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    ll n; cin >> n;
    ll ans = 0;
    for (ll i = 60; i >= 0; i--)
    {
      if (n & (1ll << i))
        ans += mpow(3, i);
    }
    cout << ans << "\n";
  }
}
