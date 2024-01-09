#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        ll n, m, k; cin >> n >> m >> k;
        bool hasAns = false;
        for (ll x = 1; x <= 1000; x++)
        {
            if (m * k * ((x + 1) / 2) - x / 2 >= n)
            {
                hasAns = true;
                cout << x << "\n";
                break;
            }
        }
        if (!hasAns)
            cout << -1 << "\n";
    }
}