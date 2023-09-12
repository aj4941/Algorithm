#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mn[100], cnt[100];
map<char, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mp['A'] = 0, mp['C'] = 1, mp['G'] = 2, mp['T'] = 3;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < 4; i++) cin >> mn[i];

    for (int i = 0; i < k; i++)
        cnt[mp[s[i]]]++;

    int ans = 0;
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] < mn[i])
            flag = false;
    }
    if (flag) ans++;
    for (int i = k; i < s.size(); i++)
    {
        flag = true;
        cnt[mp[s[i]]]++;
        cnt[mp[s[i - k]]]--;
        for (int j = 0; j < 4; j++)
        {
            if (cnt[j] < mn[j])
                flag = false;
        }
        if (flag)
            ans++;
    }

    cout << ans;
}