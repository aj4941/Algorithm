#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool hasAns = false;
        string t; cin >> t;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + t.size() - 1 >= s.size()) break;
            int curd = -1;
            bool flag = true;
            for (int j = 0; j < t.size(); j++)
            {
                int d = (s[i + j] - t[j] + 26) % 26;
                if (curd == -1) curd = d;
                else if (curd != d)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                for (int j = 0; j < s.size(); j++)
                    s[j] = ((s[j] - 'a' - curd + 26) % 26) + 'a';

                hasAns = true;
                break;
            }
        }

        if (hasAns)
        {
            cout << s;
            return 0;
        }
    }
}