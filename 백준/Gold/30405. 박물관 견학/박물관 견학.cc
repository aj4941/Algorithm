#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x; cin >> x;
            if (j == 0 || j == k - 1)
                v.push_back(x);
        }
    }

    sort(v.begin(), v.end());

    cout << v[(n * 2 - 1) / 2];
}
