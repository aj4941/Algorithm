#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool cmp(pll &a, pll &b)
{
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<pll> a;
    for (int i = 0; i < n; i++)
    {
        ll t, s; cin >> t >> s;
        a.push_back({ t, s });
    }

    sort(a.begin(), a.end(), cmp);

    ll l = -1, r = 1e9;
    while (l + 1 < r) // [l, r)
    {
        ll mid = (l + r) / 2;
        ll t = mid;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (t + a[i].first > a[i].second)
            {
                flag = false;
                break;
            }
            t += a[i].first;
        }

        if (flag) l = mid;
        else r = mid;
    }

    cout << l;
}