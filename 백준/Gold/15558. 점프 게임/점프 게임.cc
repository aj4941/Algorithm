#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

map<ti, bool> mp;
int m, k;
string s[2];

bool calc(int x, int y, int c)
{
    if (y >= m)
        return true;
    if (c - 1 >= y || s[x][y] == '0' || mp.count({ x, y, c }))
        return false;

    mp[{ x, y, c }] = true;
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> k;
    cin >> s[0] >> s[1];

    queue<ti> q; q.push({ 0, 0, 0 }); mp[{ 0, 0, 0 }] = true;
    bool hasAns = false;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = get<0>(to), y = get<1>(to), c = get<2>(to);
        // cout << x << ' ' << y << ' ' << c << endl;
        if (y >= m)
        {
            hasAns = true;
            break;
        }
        if (calc(x, y - 1, c + 1)) q.push({ x, y - 1, c + 1 });
        if (calc(x, y + 1, c + 1)) q.push({ x, y + 1, c + 1 });
        if (calc(1 - x, y + k, c + 1)) q.push({ 1 - x, y + k, c + 1 });
    }

    if (hasAns) cout << 1;
    else cout << 0;
}