#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
unordered_map<string, ll> mp, type;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int A, B, C; cin >> A >> B >> C;
    for (int i = 0; i < A; i++)
    {
        string s; cin >> s;
        ll cost; cin >> cost;
        mp[s] = cost; type[s] = 1;
    }
    for (int i = 0; i < B; i++)
    {
        string s; cin >> s;
        ll cost; cin >> cost;
        mp[s] = cost; type[s] = 2;
    }
    for (int i = 0; i < C; i++)
    {
        string s; cin >> s;
        mp[s] = 0; type[s] = 3;
    }

    int n; cin >> n;
    ll sum1 = 0, sum2 = 0, ccnt = 0;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if (type[s] == 1) sum1 += mp[s];
        else if (type[s] == 2) sum2 += mp[s];
        else ccnt++;
    }

    bool hasAns = true;
    if (ccnt > 1) hasAns = false;
    if (ccnt == 1 && sum1 + sum2 < 50000) hasAns = false;
    if (sum2 > 0 && sum1 < 20000) hasAns = false;

    if (hasAns) cout << "Okay";
    else cout << "No";
}