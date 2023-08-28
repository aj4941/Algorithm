#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i])) continue;
        mp[a[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        if (!mp.count(x))
        {
            cout << -1 << "\n";
            continue;
        }

        cout << mp[x] << "\n";
    }
}
