#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[8] = { 2, 2, 1, 1, -2, -2, -1, -1 };
int dy[8] = { -1, 1, 2, -2, 1, -1, 2, -2 };
map<string, bool> mp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s; mp[s] = true;
    int cx = s[0] - 'A' + 1, cy = s[1] - '0';
    bool hasAns = true;
    int x = cx, y = cy;

    for (int i = 1; i < 36; i++)
    {
        string s; cin >> s;
        if (mp.count(s))
        {
            cout << "Invalid";
            return 0;
        }
        mp[s] = true;
        int nx = s[0] - 'A' + 1, ny = s[1] - '0';
        bool flag = false;

        for (int k = 0; k < 8; k++)
        {
            int px = x + dx[k], py = y + dy[k];
            if (px == nx && py == ny)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            hasAns = false;
            break;
        }

        x = nx, y = ny;
    }

    bool flag = false;

    for (int k = 0; k < 8; k++)
    {
        int px = x + dx[k], py = y + dy[k];
        if (px == cx && py == cy)
        {
            flag = true;
            break;
        }
    }

    if (hasAns && flag) cout << "Valid";
    else cout << "Invalid";
}