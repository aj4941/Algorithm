#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

map<string, int> mp = {
        {"a", 1}, {"b", 2}, {"k", 3}, {"d", 4}, {"e", 5},
        {"g", 6}, {"h", 7}, {"i", 8}, {"l", 9}, {"m", 10},
        {"n", 11}, {"ng", 12}, {"o", 13}, {"p", 14}, {"r", 15},
        {"s", 16}, {"t", 17}, {"u", 18}, {"w", 19}, {"y", 20}
};

int n;
vector<string> v;

bool cmp(string &a, string &b)
{
    int i1 = 0, i2 = 0;

    while (i1 < a.size() && i2 < b.size())
    {
        string t1 = "", t2 = "";
        if (a.substr(i1, 2) == "ng")
        {
            t1 = a.substr(i1, 2);
            i1 += 2;
        }
        else
            t1 = a[i1++];

        if (b.substr(i2, 2) == "ng")
        {
            t2 = b.substr(i2, 2);
            i2 += 2;
        }
        else
            t2 = b[i2++];

        if (mp[t1] != mp[t2])
            return mp[t1] < mp[t2];
    }

    if (i1 >= a.size()) return true;
    else return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto to : v)
        cout << to << "\n";
}