#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int l = -1, r = n - 1;
    while (l + 1 < r)
    {
        bool flag = true;
        int mid = (l + r) / 2;
        unordered_map<string, int> mp;
        for (int j = 0; j < m; j++)
        {
            string res = "";
            for (int i = 0; i <= mid; i++)
                res += s[n - 1 - i][j];

            mp[res]++;

            if (mp[res] >= 2)
                flag = false;
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << n - 1 - r;
}