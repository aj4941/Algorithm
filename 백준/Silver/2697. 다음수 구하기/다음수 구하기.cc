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
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    string t = s;
    next_permutation(s.begin(), s.end());
    if (s > t)
      cout << s << "\n";
    else
      cout << "BIGGEST" << "\n";
  }
}