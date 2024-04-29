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
    int n; cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1; // v[1] = 2, v[2] = 3, ...
    ll idx = -1, cnt = 1;

    while (v.size() > 1)
    {
        idx += (cnt * cnt * cnt);
        idx %= v.size(); cnt++;
        v.erase(v.begin() + idx);
        idx = (idx - 1 + v.size()) % v.size();
    }

    cout << *v.begin();
}