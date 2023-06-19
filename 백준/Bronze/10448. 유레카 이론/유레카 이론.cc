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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a;
    int i = 0, sum = 0;
    while (true)
    {
        sum += ++i;
        a.push_back(sum);
        if (sum > 1000) break;
    }
    // for (auto to : a) cout << to << ' ';
    int t; cin >> t;
    int sz = a.size();
    while (t--)
    {
        ll n; cin >> n;
        bool hasAns = false;
        for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++)
        {
            for (int k = 0; k < sz; k++)
            {
                if (a[i] + a[j] + a[k] == n)
                    hasAns = true;
            }
        }

        if (hasAns) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}