#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    sort(v.begin(), v.end());

    bool hasAns = true;

    for (int j = 0; j < m; j++)
    {
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = i1 + 1; i2 < n; i2++)
            {
                if (v[i1][j] > v[i2][j])
                    hasAns = false;
            }
        }
    }

    if (hasAns) cout << "YES";
    else cout << "NO";
}
