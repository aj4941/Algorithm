#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };

bool cmp(pair<string, string> &a, pair<string, string> &b)
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second > b.second;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<string, string>> v;
    for (int i = 0; i < n; i++)
    {
        string a, b; cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end(), cmp);

    for (auto to : v)
        cout << to.first << ' ' << to.second << "\n";
}