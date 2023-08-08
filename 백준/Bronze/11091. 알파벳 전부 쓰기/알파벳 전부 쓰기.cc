#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    string s; getline(cin, s);
    int cnt[26] = { 0 };
    for (auto to : s)
    {
      if ('A' <= to && to <= 'Z') cnt[to - 'A']++;
      if ('a' <= to && to <= 'z') cnt[to - 'a']++;
    }
    bool hasAns = true;
    vector<char> ch;
    for (int j = 0; j < 26; j++)
    {
      if (cnt[j] == 0)
        ch.push_back(j + 'a');
    }

    if (ch.size() == 0) cout << "pangram";
    else 
    {
      cout << "missing" << ' ';
      for (auto to : ch) cout << to;
    }
    cout << "\n";
  }
  return 0;
}
