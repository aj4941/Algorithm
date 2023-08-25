#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        v.insert(v.begin() + (x - 1), i);
    }

    vector<int> v2;
    for (int i = m - 1; i >= 0; i--)
    {
        int x; cin >> x;
        v2.insert(v2.begin() + (x - 1), v[i]);
    }

    for (int i = 0; i < 3; i++)
        cout << v2[i] << "\n";
}