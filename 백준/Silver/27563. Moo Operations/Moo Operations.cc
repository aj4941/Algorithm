#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char ch[3] = { 'M', 'O', 'O' };
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        ll ans = 1e9;
        string s; cin >> s;
        int n = s.size();
        for (ll i = 0; i < n - 2; i++)
        {
            ll cnt = 0;
            bool flag = true;
            for (int k = 0; k < 3; k++)
            {
                if (ch[k] != s[i + k])
                {
                    cnt++;
                    if (k == 1)
                        flag = false;
                }
            }

            if (flag)
                ans = min(ans, (n - 3) + cnt);
        }

        if (ans == 1e9) ans = -1;
        cout << ans << "\n";
    }
}