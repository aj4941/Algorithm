#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll D, K; cin >> D >> K;
    ll a0 = 1, a1 = 0, b0 = 0, b1 = 1;
    for (ll i = 0; i < D - 2; i++)
    {
        ll na = a0 + a1;
        ll nb = b0 + b1;
        a0 = a1, a1 = na, b0 = b1, b1 = nb;
    }
    for (ll A = 1; K - a1 * A >= 0; A++)
    {
        if ((K - a1 * A) % b1 == 0)
        {
            ll B = (K - a1 * A) / b1;
            if (A <= B)
            {
                cout << A << "\n" << B;
                return 0;
            }
        }
    }
}