#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
map<string, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a, b, c; cin >> a >> b >> c;
        for (int k1 = 0; k1 < 2; k1++) for (int k2 = 0; k2 < 2; k2++) for (int k3 = 0; k3 < 2; k3++)
        {
            string r1 = (k1 == 0) ? a : "-";
            string r2 = (k2 == 0) ? b : "-";
            string r3 = (k3 == 0) ? c : "-";
            string res = r1 + r2 + r3; mp[res]++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        string a, b, c; cin >> a >> b >> c;
        string res = a + b + c;
        cout << mp[res] << "\n";
    }
}