#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    bool hasAns = true;
    ll L; cin >> L;
    ll ML, MK; cin >> ML >> MK;
    ll C; cin >> C;
    queue<ll> q;
    for (ll i = 1; i <= ML - 1; i++) q.push(0);
    ll d = 0;
    for (ll i = 1; i <= L; i++)
    {
        ll x; cin >> x;
        ll cnt = min(ML, i) - 1 - d;
        ll damage = cnt * MK + MK;
        if (q.size() && q.front() == 1) d--;
        if (q.size()) q.pop();
        if (x - damage <= 0)
        {
            if (ML - 1 >= 1)
                q.push(0);
        }
        else if (C > 0)
        {
            C--;
            if (ML - 1 >= 1)
            {
                q.push(1);
                d++;
            }
        }
        else
        {
            hasAns = false;
            break;
        }
    }

    if (hasAns) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
