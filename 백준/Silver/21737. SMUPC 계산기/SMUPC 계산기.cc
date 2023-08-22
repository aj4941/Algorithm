#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    ll r1 = 0, r2 = 0;

    vector<ll> ans;
    char ch = '?';

    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            if (!flag) r1 = r1 * 10 + (s[i] - '0');
            else r2 = r2 * 10 + (s[i] - '0');
        }
        else if (s[i] == 'C')
        {
            if (ch == 'S') r1 -= r2, r2 = 0;
            if (ch == 'M') r1 *= r2, r2 = 0;
            if (ch == 'U') r1 /= r2, r2 = 0;
            if (ch == 'P') r1 += r2, r2 = 0;

            ans.push_back(r1);
            ch = '?';
        }
        else
        {
            if (ch == '?')
            {
                ch = s[i];
                flag = true;
                continue;
            }
            if (ch == 'S') r1 -= r2, r2 = 0;
            if (ch == 'M') r1 *= r2, r2 = 0;
            if (ch == 'U') r1 /= r2, r2 = 0;
            if (ch == 'P') r1 += r2, r2 = 0;

            ch = s[i];
        }
    }

    if (ans.size() == 0)
        cout << "NO OUTPUT";
    else
    {
        for (auto to : ans)
            cout << to << ' ';
    }
}