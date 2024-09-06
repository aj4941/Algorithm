#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll ans = 0;
    int n; cin >> n;
    vector<ll> p, m;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if (x == 0) flag = true;
        else if (x == 1) ans++;
        else if (x > 0) p.push_back(x);
        else m.push_back(x);
    }

    sort(p.rbegin(), p.rend());
    sort(m.begin(), m.end());

    for (int i = 0; i < (int)p.size() - 1; i += 2)
        ans += p[i] * p[i + 1];

    if (p.size() % 2) ans += p.back();

    for (int i = 0; i < (int)m.size() - 1; i += 2)
        ans += m[i] * m[i + 1];

    if (m.size() % 2 && !flag) ans += m.back();

    cout << ans;
}