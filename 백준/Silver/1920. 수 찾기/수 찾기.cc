#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int m; cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        int l = 0, r = n;

        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= x) l = mid;
            else r = mid;
        }

        if (a[l] == x) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}