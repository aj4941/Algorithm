#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool calc(vector<int> &a, vector<int> &b)
{
    bool hasAns = true;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        string a, b; cin >> a >> b;
        vector<int> cnt(26), ccnt(26);
        for (int i = 0; i < b.size(); i++) cnt[b[i] - 'a']++;

        for (int i = 0; i < b.size(); i++) ccnt[a[i] - 'a']++;

        bool hasAns = calc(cnt, ccnt);

        for (int i = b.size(); i < a.size(); i++)
        {
            ccnt[a[i - b.size()] - 'a']--;
            ccnt[a[i] - 'a']++;

            if (calc(cnt, ccnt))
                hasAns = true;
        }

        if (hasAns) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}