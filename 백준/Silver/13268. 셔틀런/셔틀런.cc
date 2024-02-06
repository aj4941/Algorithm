#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> v = { 0, 1, 0, 1, 2, 1, 0, 1, 2, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll num; cin >> num;
    ll idx = 0;
    int n = v.size();

    while (true)
    {
        if (num == 0)
        {
            cout << v[idx];
            return 0;
        }
        num -= 5;
        idx = (idx + 1) % n;

        if (num < 0)
        {
            if (v[(idx - 1 + n) % n] < v[idx])
                cout << v[idx];
            else
                cout << v[(idx - 1 + n) % n];

            return 0;
        }
    }
}