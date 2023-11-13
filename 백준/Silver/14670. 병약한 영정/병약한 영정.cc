#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int me, mn; cin >> me >> mn;
        mp[me] = mn;
    }
    int t; cin >> t;
    while (t--)
    {
        int sz; cin >> sz;
        vector<int> ans;
        bool hasAns = true;
        for (int i = 0; i < sz; i++)
        {
            int x; cin >> x;
            if (!mp.count(x))
                hasAns = false;
            else
                ans.push_back(mp[x]);
        }

        if (hasAns)
        {
            for (auto to : ans)
                cout << to << ' ';
        }
        else
            cout << "YOU DIED";

        cout << "\n";
    }
}