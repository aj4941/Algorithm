#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 200;
vector<string> a, b;
int t, n, m;
bool cache[N][N];

void move()
{
    vector<string> nb(m);
    for (int i = 0; i < m; i++) nb[i] = string(m, 'a');
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++)
        nb[j][m - 1 - i] = b[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++)
        b[i][j] = nb[i][j];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        a.clear(); b.clear();
        for (int i = 0; i < n; i++)
        {
            string s; cin >> s;
            a.push_back(s);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string s; cin >> s;
            b.push_back(s);
        }

        bool hasAns = false;
        memset(cache, false, sizeof cache);
        
        for (int k = 0; k < 4; k++)
        {
            move();
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            {
                if (i + m - 1 >= n || j + m - 1 >= n) continue;
                bool flag = true;
                
                for (int x = 0; x < m; x++) for (int y = 0; y < m; y++)
                {
                    if (a[i + x][j + y] == '.' && b[x][y] == '*')
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    for (int x = 0; x < m; x++) for (int y = 0; y < m; y++)
                    {
                        if (a[i + x][j + y] == '*' && b[x][y] == '*')
                            cache[i + x][j + y] = true;
                    }
                }
            }

            bool flag = true;

            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '*' && !cache[i][j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                hasAns = true;
                break;
            }
        }

        if (hasAns)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}