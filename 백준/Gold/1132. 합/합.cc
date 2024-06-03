#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool notFirst[12];
ll val[12];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        notFirst[s.front() - 'A'] = true;
        reverse(s.begin(), s.end());
        ll cnt = 1;
        for (auto to : s)
        {
            val[to - 'A'] += cnt;
            cnt *= 10;
        }
    }

    vector<pll> vec;

    for (int i = 0; i < 10; i++)
    {
        if (val[i] > 0)
            vec.push_back({ val[i], i });
    }

    sort(vec.begin(), vec.end());

    if (vec.size() == 10)
    {
        vector<bool> check(10, false);
        for (auto to : vec)
        {
            if (!notFirst[to.second])
            {
                check[to.second] = true;
                break;
            }
        }
        ll ans = 0, cnt = 1;
        for (auto to : vec)
        {
            if (check[to.second]) continue;
            ans += to.first * cnt++;
        }

        cout << ans;
    }
    else
    {
        reverse(vec.begin(), vec.end());
        ll ans = 0, cnt = 9;
        for (auto to : vec)
            ans += to.first * cnt--;

        cout << ans;
    }
}