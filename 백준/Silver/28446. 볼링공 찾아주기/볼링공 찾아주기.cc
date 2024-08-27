#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
unordered_map<int, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l; cin >> l;
        if (l == 1)
        {
            int x, w; cin >> x >> w;
            mp[w] = x;
        }
        else
        {
            int w; cin >> w;
            cout << mp[w] << "\n";
        }
    }
}