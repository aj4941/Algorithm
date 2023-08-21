#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int r[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int u = i + 1;
        while (r[x] != 0)
        {
            int nu = r[x];
            r[x] = u;
            u = nu; x++;
        }
        r[x] = u;
    }

    vector<int> vec;
    for (int i = 1; i <= m; i++)
        vec.push_back(r[i]);

//    for (auto to : vec)
//        cout << to << ' ';
//    cout << endl;

    memset(r, 0, sizeof r);

    for (int i = 0; i < m; i++)
    {
        int x = b[i];
        int u = vec[m - 1 - i];
        while (r[x] != 0)
        {
            int nu = r[x];
            r[x] = u;
            u = nu; x++;
        }
        r[x] = u;
    }

    for (int i = 1; i <= 3; i++)
        cout << r[i] << "\n";
}