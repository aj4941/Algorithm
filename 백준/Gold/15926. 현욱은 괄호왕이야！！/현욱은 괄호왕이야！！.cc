#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 200020;
int res[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(res, -1, sizeof res);
    int n; cin >> n;
    string s; cin >> s;
    int qcnt = 0, val = 0, ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '(')
        {
            val++;
            if (res[val] == -1) res[val] = i;
        }
        else // ')'
        {
            val--;
            if (val < 0)
            {
                int tmp = 1;
                while (res[tmp] != -1) res[tmp++] = -1;
                val = 0;
            }
            else
            {
                int tmp = val + 2;
                while (res[tmp] != -1) res[tmp++] = -1;
            }

            if (res[val + 1] != -1)
                ans = max(ans, i - res[val + 1] + 1);
        }
    }

    cout << ans;
}