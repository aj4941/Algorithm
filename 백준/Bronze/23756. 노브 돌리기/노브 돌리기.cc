#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, a; cin >> n >> a;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int na; cin >> na;
        int r1 = (na - a + 360) % 360;
        int r2 = (a - na + 360) % 360;
        ans += min(r1, r2);
        a = na;
    }

    cout << ans;
}
