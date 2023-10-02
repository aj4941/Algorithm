#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string tmp; cin >> tmp;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    bool hasAns = false;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 8; k++)
        {
            string res = ""; res += s[i][j];
            int x = i, y = j;
            while (true)
            {
                if (tmp == res)
                {
                    hasAns = true;
                    break;
                }
                x += dx[k], y += dy[k];
                if (x < 0 || y < 0 || x >= n || y >= m) break;
                res += s[x][y];
            }

            if (hasAns)
                break;
        }
        if (hasAns)
            break;
    }

    if (hasAns) cout << 1;
    else cout << 0;
}