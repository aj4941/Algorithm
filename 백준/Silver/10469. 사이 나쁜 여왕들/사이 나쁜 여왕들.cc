#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
string s[10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    for (int i = 0; i < 8; i++) cin >> s[i];

    bool hasAns = true;

    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
    {
        if (s[i][j] == '*')
        {
            cnt++;
            for (int k = 0; k < 8; k++)
            {
                int x = i, y = j;
                bool flag = true;
                while (true)
                {
                    x += dx[k], y += dy[k];
                    if (x < 0 || y < 0 || x >= 8 || y >= 8) break;
                    if (s[x][y] == '*') flag = false;
                }

                if (!flag)
                    hasAns = false;
            }
        }
    }

    if (hasAns && cnt == 8) cout << "valid";
    else cout << "invalid";
}