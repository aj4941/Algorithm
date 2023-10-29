#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<ll> v;
    ll n; cin >> n;
    ll res = 0; 
    queue<ll> q;
    for (ll i = 0; i <= 9; i++)
    {
        v.push_back(i);
        q.push(i);
    }

    while (!q.empty())
    {
        ll x = q.front(); q.pop();
        ll c = x % 10;
        for (ll i = 0; i < c; i++)
        {
            ll nx = x * 10 + i;
            v.push_back(nx);
            q.push(nx);
        }
    }

    if (n - 1 >= v.size()) cout << -1;
    else cout << v[n - 1];
}