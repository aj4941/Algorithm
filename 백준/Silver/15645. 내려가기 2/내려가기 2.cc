#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int mdp[N][5], Mdp[N][5];
int a[N][5];
int n;

int solve(int i, int j, int c, int dp[N][5])
{
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  if (i == n) return ret = 0;
  if (c == -1) ret = 1e9;
  else ret = -1e9;

  for (int nj = j - 1; nj <= j + 1; nj++)
  {
    if (nj < 0 || nj >= 3) continue;
    if (c == -1) ret = min(ret, solve(i + 1, nj, -1, dp) + a[i][j]);
    else ret = max(ret, solve(i + 1, nj, 1, dp) + a[i][j]);
  }

  return ret;
}

int main(void) 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(mdp, -1, sizeof mdp); memset(Mdp, -1, sizeof Mdp);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];
  }

  int mn = 1e9, mx = -1e9;

  for (int j = 0; j < 3; j++)
  {
    mn = min(mn, solve(0, j, -1, mdp));
    mx = max(mx, solve(0, j, 1, Mdp));
  }

  cout << mx << ' ' << mn;

  return 0;
}