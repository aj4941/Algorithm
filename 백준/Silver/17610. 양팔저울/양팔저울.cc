#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
const int N = 20;
const int MAX = 5000000;
int n, a[N];
bool cache[MAX];

void solve(int idx, int asum, int bsum)
{
    if (idx == n)
    {
        cache[abs(asum - bsum)] = true;
        return;
    }
    solve(idx + 1, asum, bsum);
    solve(idx + 1, asum + a[idx], bsum);
    solve(idx + 1, asum, bsum + a[idx]);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    solve(0, 0, 0);

    int ans = 0;

    for (int i = 1; i <= sum; i++)
    {
        if (!cache[i])
            ans++;
    }

    cout << ans;
}