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
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll x; cin >> x;
        ll res = 0;
        for (ll j = 1; j * j <= x; j++)
        {
            if (x % j) continue;
            if (j != x) res += j;
            if ((x / j != j) && (x / j != x)) res += (x / j);
        }

        if (res < x) cout << "Deficient" << "\n";
        else if (res == x) cout << "Perfect" << "\n";
        else cout << "Abundant" << "\n";
    }
}