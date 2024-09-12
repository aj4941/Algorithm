#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> s(5);
    map<string, string> mp;
    mp[".omln"] = "owln."; mp["owln."] = ".omln";
    for (int i = 0; i < 5; i++) cin >> s[i];

    int n = 5, m = s[0].size();

    for (int j = 0; j < m; j++)
    {
        string t = "";
        for (int i = 0; i < 5; i++) t += s[i][j];
        if (!mp.count(t)) continue;
        t = mp[t];
        for (int i = 0; i < 5; i++) s[i][j] = t[i];
    }

    for (auto to : s)
        cout << to << "\n";
}