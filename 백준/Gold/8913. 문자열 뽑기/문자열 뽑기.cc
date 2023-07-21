#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int t;
string s;
unordered_map<string, int> mp;

int solve(string &cur)
{
    if (cur.size() == 0) return 1;
    if (mp.count(cur)) return mp[cur];
    mp[cur] = 0;
    int st = 0, ed = 0;
    for (int i = 0; i < (int)cur.size() - 1; i++)
    {
        if (cur[i] == cur[i + 1])
            ed = i + 1;
        else
        {
            if (ed - st + 1 >= 2)
            {
                string tmp = cur.substr(0, st);
                if (ed + 1 < cur.size()) tmp += cur.substr(ed + 1);
                mp[cur] |= solve(tmp);
            }
            st = ed = i + 1;
        }
    }

    if (ed - st + 1 >= 2)
    {
        string tmp = cur.substr(0, st);
        if (ed + 1 < cur.size()) tmp += cur.substr(ed + 1);
        mp[cur] |= solve(tmp);
    }

    return mp[cur];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        mp.clear(); cin >> s;
        cout << solve(s) << "\n";
    }
}