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
    string a, b, c; cin >> a >> b >> c;
    ll ans = 0;
    if ('0' <= a[0] && a[0] <= '9') ans = stoll(a) + 3;
    if ('0' <= b[0] && b[0] <= '9') ans = stoll(b) + 2;
    if ('0' <= c[0] && c[0] <= '9') ans = stoll(c) + 1;

    if ((ans % 3 == 0) && (ans % 5 == 0)) cout << "FizzBuzz";
    else if ((ans % 3 == 0) && (ans % 5)) cout << "Fizz";
    else if ((ans % 3) && (ans % 5 == 0)) cout << "Buzz";
    else cout << ans;
}