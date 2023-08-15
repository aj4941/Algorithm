#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  vector<pii> a;
  int n; cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    a.push_back({ x, y });
  }

  sort(a.begin(), a.end());

  vector<int> b;

  for (int i = 0; i < n; i++)
    b.push_back(a[i].second);

  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int idx = upper_bound(v.begin(), v.end(), b[i]) - v.begin();
    if (idx == v.size()) v.push_back(b[i]);
    else v[idx] = b[i];
  }

  cout << v.size();
}
