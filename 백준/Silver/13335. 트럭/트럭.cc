#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, w, l; cin >> n >> w >> l;
    vector<int> a(n), v(w);
    for (int i = 0; i < n; i++) cin >> a[i];

    int idx = 0, sum = 0, cnt = 0, truck = 0;

    while (true)
    {
        if (v[w - 1] != 0)
        {
            sum -= v[w - 1];
            truck--;
        }
        for (int i = w - 1; i >= 0; i--) v[i] = v[i - 1];
        v[0] = 0;

        if (idx < n && a[idx] + sum <= l)
        {
            truck++;
            sum += a[idx];
            v[0] = a[idx++];
        }

        cnt++;

        if (idx == n && truck == 0)
            break;
    }

    cout << cnt;
}