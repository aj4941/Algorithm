#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 1000002;
ll a, b;
ll p[N];
map<ll, ll> mp;
vector<ll> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (ll i = 2; i <= 1e6; i++) p[i] = i;

    for (ll i = 2; i <= 1e6; i++)
    {
        if (p[i] != i) continue;
        for (ll j = i; j <= 1e6; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }

    for (ll i = 2; i <= 1e6; i++)
    {
        if (p[i] == i)
            v.push_back(i);
    }

    mp[a] = 1;

    while (a > 1)
    {
        for (auto to : v)
        {
            if (to * to > a)
            {
                a /= a;
                break;
            }
            if (a % to == 0)
            {
                a /= to;
                break;
            }
        }
        mp[a] = 1;
    }

    while (true)
    {
        if (mp[b] == 1)
        {
            cout << b;
            return 0;
        }
        for (auto to : v)
        {
            if (to * to > b)
            {
                b /= b;
                break;
            }
            if (b % to == 0)
            {
                b /= to;
                break;
            }
        }
    }
}