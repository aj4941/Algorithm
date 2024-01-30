#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int l = 0, r = n / 2 + 1;
    while (l + 1 < r) // [l, r)
    {
        int mid = (l + r) / 2;
        bool flag = true;
        for (int i = 0; i < mid; i++)
        {
            if (a[i] + a[2 * mid - 1 - i] < m)
                flag = false;
        }

        if (flag) l = mid;
        else r = mid;
    }

    cout << l;
}