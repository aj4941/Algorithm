#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
map<int, bool> cache;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cache[v[i]] = true;
    }

    sort(v.begin(), v.end());

    int ans = 5;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (cache[v[i] + j] == true)
                cnt++;
        }

        ans = min(ans, 5 - cnt);
    }

    cout << ans;
}