#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
const int N = 100;
int r, c;
int a[N][N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
        cin >> a[i][j];

    int T; cin >> T;
    int ans = 0;

    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
    {
        vector<int> v;
        int ni = i + 3, nj = j + 3;
        if (ni > r || nj > c) continue;
        for (int x = i; x < ni; x++) for (int y = j; y < nj; y++)
            v.push_back(a[x][y]);

        sort(v.begin(), v.end());
        if (v[4] >= T) ans++;
        // cout << "mid : " << v[4] << endl;
    }

    cout << ans;
}