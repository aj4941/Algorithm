#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string t; cin >> t;
        bool hasAns = false;
        for (int st = 0; st < t.size(); st++)
        {
            int k = 1;
            while (k < t.size())
            {
                bool flag = true;
                int idx = st, sidx = 0;
                while (true)
                {
                    if (t[idx] != s[sidx])
                    {
                        flag = false;
                        break;
                    }
                    sidx++;
                    idx += k;

                    if (idx >= t.size() || sidx >= s.size())
                        break;
                }

                if (sidx < s.size())
                    flag = false;

                if (flag)
                {
                    hasAns = true;
                    break;
                }
                k++;
            }
            if (hasAns)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}