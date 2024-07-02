#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int mv = 0; mv < 26; mv++) // 26
    {
        string ns = s;

        for (int i = 0; i < ns.size(); i++) // 100
            ns[i] = ((ns[i] - 'a' + mv) % 26) + 'a';

        bool hasAns = false;

        for (int i = 0; i < v.size(); i++) // 20
        {
            bool flag = false;

            for (int j = 0; j < ns.size(); j++) // 100
            {
                if (ns.substr(j, v[i].size()) == v[i])
                {
                    flag = true;
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
        {
            cout << ns;
            return 0;
        }
    }
}
