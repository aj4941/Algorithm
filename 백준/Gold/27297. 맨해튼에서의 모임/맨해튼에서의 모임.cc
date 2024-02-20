#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1002;
vector<ll> v[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll x; cin >> x;
            v[j].push_back(x);
        }
    }

    for (int j = 0; j < n; j++)
        sort(v[j].begin(), v[j].end());

    vector<ll> ans;

    for (int j = 0; j < n; j++)
        ans.push_back(v[j][v[j].size() / 2]);

    ll value = 0;

    for (int j = 0; j < n; j++)
    {
        for (auto to : v[j])
            value += abs(to - ans[j]);
    }

    cout << value << "\n";
    for (auto to : ans)
        cout << to << ' ';
}