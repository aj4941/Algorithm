#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool calc(string tmp)
{
    int len = tmp.size();
    string l = tmp.substr(0, len / 2);
    string r = tmp.substr(len / 2);
    int lsum = 0, rsum = 0;
    for (auto to : l) lsum += (to - '0');
    for (auto to : r) rsum += (to - '0');

    return (lsum == rsum);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int len = 1; len <= s.size(); len++)
        {
            string tmp = s.substr(i, len);
            if (tmp.size() % 2) continue;
            if (calc(tmp)) ans = max(ans, (int)tmp.size());
        }
    }

    cout << ans;
}