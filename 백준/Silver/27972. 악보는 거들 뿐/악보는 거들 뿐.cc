#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1, cur = 1;
    bool up = false, down = false;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            if (up) cur++;
            else cur = 2, up = true, down = false;
        }
        else if (a[i - 1] > a[i])
        {
            if (down) cur++;
            else cur = 2, up = false, down = true;
        }
        ans = max(ans, cur);
    }

    cout << ans;
}