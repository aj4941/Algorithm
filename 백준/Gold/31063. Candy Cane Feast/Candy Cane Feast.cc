#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> cow(n), candy(m), eat(m);
    for (int i = 0; i < n; i++) cin >> cow[i];
    for (int i = 0; i < m; i++) cin >> candy[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cow[j] <= eat[i]) continue;
            int val = min(cow[j], candy[i]);
            cow[j] += val - eat[i];
            eat[i] = val;
            
            if (eat[i] == candy[i]) 
                break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << cow[i] << "\n";
}