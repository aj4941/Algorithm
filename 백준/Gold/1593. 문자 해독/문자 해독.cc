#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int Scache[100], Tcache[100];

int calc()
{
    for (int i = 0; i < 60; i++)
    {
        if (Scache[i] != Tcache[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int cnt = 0;
    string t, s; cin >> t >> s;
    for (int i = 0; i < t.size(); i++)
    {
        int Sval = (s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
        int Tval = (t[i] <= 'Z') ? t[i] - 'A' : t[i] - 'a' + 26;
        Scache[Sval]++; Tcache[Tval]++;
    }

    int ans = calc();

    for (int i = t.size(); i < s.size(); i++)
    {
        int Sval = (s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
        Scache[Sval]++;
        Sval = (s[i - t.size()] <= 'Z') ? s[i - t.size()] - 'A' : s[i - t.size()] - 'a' + 26;
        Scache[Sval]--;
        ans += calc();
    }

    cout << ans;
}