#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll x, ll y) {
    return ((y) ? gcd(y, x % y) : x);
}
map<string, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        int cnt; cin >> cnt;
        mp[s] += cnt;
    }

    bool flag = false;

    for (auto to : mp)
    {
        if (to.second == 5)
            flag = true;
    }

    if (flag) cout << "YES";
    else cout << "NO";
}