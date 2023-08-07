#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt[26] = { 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof cnt);
        string s; cin >> s;
        bool hasAns = true;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'A';
            cnt[idx]++;
            if (cnt[idx] == 3)
            {
                if (i + 1 < s.size() && s[i] == s[i + 1])
                {
                    cnt[idx] = 0; i++;
                    continue;
                }
                else
                {
                    hasAns = false;
                    break;
                }
            }
        }

        if (hasAns)
            cout << "OK" << "\n";
        else
            cout << "FAKE" << "\n";
    }
}