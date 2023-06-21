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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 10000002;
int p[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (ll i = 2; i < N; i++) p[i] = i;
    for (ll i = 2; i < N; i++)
    {
        if (p[i] != i) continue;
        for (ll j = i * i; j < N; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }

    vector<ll> v;
    for (int i = 2; i < N; i++)
    {
        if (p[i] == i)
            v.push_back(i);
    }

    ll A, B; cin >> A >> B;
    ll ans = 0;
    map<ll, bool> mp;

    for (int i = 0; i < v.size(); i++)
    {
        ll res = v[i] * v[i]; // res * v[i] <= B
        while (true)
        {
            if (!mp.count(res) && A <= res && res <= B)
            {
                mp[res] = true;
                ans++;
            }
            if (res <= 1e18 / v[i])
                res *= v[i];
            else
                break;
        }
    }

    cout << ans;
}