#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 102;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string s[N];
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
        {
            int cnt = 0;
            int val = s[i][j] - '0';

            for (int k = 0; k < 8; k++)
            {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                if (s[ni][nj] == '*') cnt++;
            }

            int rm = val - cnt;

            for (int k = 0; k < 8; k++)
            {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                if (s[ni][nj] != '#') continue;
                if (rm > 0)
                {
                    s[ni][nj] = '*';
                    rm--;
                }
                else
                    s[ni][nj] = '.';
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (s[i][j] == '*' || s[i][j] == '#')
            ans++;
    }

    cout << ans;
}