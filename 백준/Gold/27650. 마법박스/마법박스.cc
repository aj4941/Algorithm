#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tll;
const int N = 5000002;
ll p[N];

int main(void)
{
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] != i) continue;
        for (int j = i; j <= n; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }
    vector<ll> a;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == i)
            a.push_back(i);
    }

    ll l = -1, r = (int)a.size() - 1;

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        cout << "? " << a[mid] << endl;
        ll x; cin >> x;
        if (x == 1) l = mid;
        else r = mid;
    }

    cout << "! " << a[r] << endl;
}