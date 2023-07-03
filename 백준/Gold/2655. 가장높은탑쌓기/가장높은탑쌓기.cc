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
const int N = 105;
const int MAX = 10005;
int n;
ll dp[N][N * N];
vector<tuple<ll, ll, ll, ll>> v;

ll solve(int idx, ll W)
{
    ll &ret = dp[idx][W];
    if (idx == n) return ret = 0;
    if (ret != -1) return ret;
    ret = 0;
    ll h = get<1>(v[idx]), w = get<2>(v[idx]);
    ret = max(ret, solve(idx + 1, W));
    if (W >= w) ret = max(ret, solve(idx + 1, w) + h);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll s, h, w; cin >> s >> h >> w;
        v.push_back({ s, h, w, i }); // 넓이, 높이, 무게, 인덱스
    }

    sort(v.rbegin(), v.rend());

    solve(0, MAX);

    int idx = 0, W = MAX;
    vector<int> ans;

    while (idx < n)
    {
        ll h = get<1>(v[idx]), w = get<2>(v[idx]), i = get<3>(v[idx]);
        if (W < w)
        {
            idx++;
            continue;
        }
        ll r1 = dp[idx + 1][W];
        ll r2 = dp[idx + 1][w] + h;

        if (r2 == dp[idx][W])
        {
            ans.push_back(i + 1);
            idx++; W = w;
        }
        else
            idx++;
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (auto to : ans) cout << to << "\n";
}