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
    ll n; cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        ll mn = min(d, c - b); c -= mn, d -= mn;
        mn = min(d, (b + c) - 2 * a); b -= mn / 2, c -= mn / 2, d -= (mn / 2 + mn / 2);
        if (d == 0) cout << a * b * c << "\n";
        else
        {
            if (a != b) b--;
            else
            {
                a -= d / 3, b -= d / 3, c -= d / 3;
                if (d % 3 == 1) a--;
                else if (d % 3 == 2) a--, b--;
            }
            cout << a * b * c << "\n";
        }
    }
}