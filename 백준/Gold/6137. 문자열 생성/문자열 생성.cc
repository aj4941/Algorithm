#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 2002;
int n;
string s;
char lch[N], rch[N];

bool calc(int l, int r)
{
    while (l < r)
    {
        if (s[l] == s[r]) l++, r--;
        else if (s[l] < s[r]) return true;
        else return false;
    }
}

string solve(int l, int r)
{
    if (l == r) return string("") + s[l];
    else if (s[l] < s[r]) return s[l] + solve(l + 1, r);
    else if (s[l] > s[r]) return s[r] + solve(l, r - 1);
    else
    {
        if (calc(l, r)) return s[l] + solve(l + 1, r);
        else return s[r] + solve(l, r - 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        s += c;
    }

    if (n == 1)
    {
        cout << s;
        return 0;
    }

    string ans = solve(0, n - 1);
    int idx = 0, len = 80;
    while (true)
    {
        cout << ans.substr(idx, len) << "\n";
        idx += len;
        if (idx >= ans.size()) break;
    }
}