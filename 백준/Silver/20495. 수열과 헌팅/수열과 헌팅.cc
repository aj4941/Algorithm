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
const int N = 500004;
vector<pii> l, r;
pii ans[N];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        l.push_back({ a - b, i }); r.push_back({ a + b, i });
    }

    sort(l.begin(), l.end()); sort(r.begin(), r.end());

    for (int i = 0; i < n; i++)
    {
        int val = l[i].first;
        int idx = lower_bound(r.begin(), r.end(), pii(val, -1e9)) - r.begin();
        ans[l[i].second].first = idx + 1;

        val = r[i].first;
        idx = lower_bound(l.begin(), l.end(), pii(val, 1e9)) - l.begin();
        ans[r[i].second].second = idx;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i].first << ' ' << ans[i].second << "\n";
}