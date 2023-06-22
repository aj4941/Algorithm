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
const int N = 200;
string s;
int n;
int dp[N];

bool solve(int idx)
{
    int &ret = dp[idx];
    if (idx == n) return ret = 1;
    if (ret != -1) return ret;
    ret = 0;
    if (s[idx] == '0')
    {
        if (idx + 1 < n && s[idx + 1] == '1')
            ret |= solve(idx + 2);
    }
    else // s[idx] == '1'
    {
        int cnt = 0, nidx = -1;
        for (int i = idx + 1; i < n; i++)
        {
            if (s[i] == '0')
                cnt++;
            else
            {
                nidx = i;
                break;
            }
        }

        if (nidx != -1 && cnt >= 2)
        {
            for (int i = nidx; i < n; i++)
            {
                if (s[i] == '1')
                    ret |= solve(i + 1);
                else
                    break;
            }
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s; n = s.size();

    if (solve(0)) cout << "SUBMARINE";
    else cout << "NOISE";
}