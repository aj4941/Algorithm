#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tc = 0;
  while (++tc) {
    int a; cin >> a;
    string s; cin >> s;
    int b; cin >> b;

    if (s == "E") break;

    cout << "Case " << tc << ": "; 

    if (s == ">")
    {
      if (a > b) cout << "true";
      else cout << "false";
    }
    if (s == ">=")
    {
      if (a >= b) cout << "true";
      else cout << "false";
    }
    if (s == "<")
    {
      if (a < b) cout << "true";
      else cout << "false";
    }
    if (s == "<=")
    {
      if (a <= b) cout << "true";
      else cout << "false";
    }
    if (s == "==")
    {
      if (a == b) cout << "true";
      else cout << "false";
    }
    if (s == "!=")
    {
      if (a != b) cout << "true";
      else cout << "false";
    }
    cout << "\n";
  }
  
  return 0;
}
