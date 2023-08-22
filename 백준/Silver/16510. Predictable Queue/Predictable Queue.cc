#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    ll sum = 0;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        sum += x;
        v.push_back(sum);
    }

    for (int i = 0; i < m; i++)
    {
        ll x; cin >> x;
        ll idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << idx << "\n";
    }
}