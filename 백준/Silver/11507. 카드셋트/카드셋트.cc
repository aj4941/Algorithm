#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    map<string, int> mp;
    vector<int> v(100, 13);

    for (int i = 0; i < s.size(); i += 3)
    {
        string tmp = s.substr(i, 3);
        mp[tmp]++; v[tmp[0] - 'A']--;

        if (mp[tmp] > 1)
        {
            cout << "GRESKA";
            return 0;
        }
    }

    //  P, K, H, T
    cout << v['P' - 'A'] << ' ' << v['K' - 'A']
        << ' ' << v['H' - 'A'] << ' ' << v['T' - 'A'];
}