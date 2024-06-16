#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] != s[i])
            cnt++;
    }

    cout << cnt / 2;
}