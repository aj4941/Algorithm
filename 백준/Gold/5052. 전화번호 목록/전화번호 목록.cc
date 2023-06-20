#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<string> a(n);
        map<string, bool> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = true;
        }

        bool hasAns = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= (int)a[i].size() - 1; j++)
            {
                string tmp = a[i].substr(0, j);
                if (mp.count(tmp)) hasAns = false;
            }
        }

        if (hasAns) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}