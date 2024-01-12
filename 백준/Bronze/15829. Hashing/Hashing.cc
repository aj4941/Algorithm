#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    int n; cin >> n;
    string st; cin >> st;
    ll r = 1, M = 1234567891, ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += ((st[i] - 'a' + 1) * r) % M;
        ans %= M;
        r = r * 31 % M;
    }
    cout << ans;
}