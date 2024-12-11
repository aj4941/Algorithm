#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, X; cin >> n >> X;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = n + 1;
    while (l + 1 < r) 
    {
        ll mid = (l + r) / 2;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll i = 0; i < mid; i++) pq.push(0);
        bool flag = true;
        for (ll i = 0; i < n; i++)
        {
            ll v = pq.top(); pq.pop();
            if (v + a[i] > X)
            {
                flag = false;
                break;
            }
            else
                pq.push(v + a[i]);
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << r;
}