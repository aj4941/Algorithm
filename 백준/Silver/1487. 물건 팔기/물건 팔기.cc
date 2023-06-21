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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    int ans_M = 0, getM = 0;
    
    for (int M = 1; M <= 1e6; M++)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first < M) continue;
            int val = M - a[i].second;
            if (val < 0) continue;
            res += val;
        }

        if (res > getM)
        {
            getM = res;
            ans_M = M;
        }
    }

    cout << ans_M;
}