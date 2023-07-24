#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 100002;
double a[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    double ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
        ans += a[i] / 2;
    ans += a[n - 1];

    cout << fixed << setprecision(5) << ans;
}