#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true)
    {
        int len; cin >> len;
        cin.ignore();
        if (len == 0) break;
        string s; getline(cin, s);
        int n = s.size();
        map<int, int> mp;
        int l = 0, r = 0, cnt = 1; mp[s[0]] = 1;
        int ans = 0;
        while (true)
        {
            if (cnt > len)
            {
                if (mp[s[l]] == 1) cnt--;
                mp[s[l]]--; l++;
            }
            else
            {
                ans = max(ans, r - l + 1);
                if (r + 1 == n) break;
                if (mp[s[r + 1]] == 0) cnt++;
                mp[s[r + 1]]++; r++;
            }
        }

        cout << ans << "\n";
    }
}