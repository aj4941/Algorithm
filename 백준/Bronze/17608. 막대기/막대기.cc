#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int mx = a[n - 1], cnt = 1;
  for (int i = n - 2; i >= 0; i--)
  {
    if (a[i] > mx)
    {
      cnt++;
      mx = a[i];
    }
  }

  cout << cnt;
  
  return 0;
}
