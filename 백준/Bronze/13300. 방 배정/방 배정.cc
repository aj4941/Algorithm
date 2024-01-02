#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int n, k;
int cnt[10][10];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int s, y; cin >> s >> y;
        cnt[s][y]++;
    }

    int ans = 0;

    for (int i = 0; i <= 1; i++) for (int j = 1; j <= 6; j++)
        ans += (cnt[i][j] + k - 1) / k;

    cout << ans;
}