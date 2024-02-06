#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    while (a.size() > 1)
    {
        vector<pll> sa;
        for (int i = 0; i < a.size(); i++)
        {
            ll val = 0;
            if (sa.size() > 0 && sa.back().first <= a[i].first)
            {
                val += sa.back().first;
                sa.pop_back();
            }
            bool flag = false;
            if (i + 1 < a.size() && a[i + 1].first <= a[i].first)
            {
                val += a[i + 1].first;
                flag = true;
            }
            
            a[i].first += val;
            sa.push_back(a[i]);
            
            if (flag) i++;
        }
        a.clear();
        a = sa;
    }

    cout << a[0].first << "\n" << a[0].second;
}