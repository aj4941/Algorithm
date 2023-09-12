#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        set<int> a, b;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            b.insert(x);
        }

        int ans = 0;

        while (a.size())
        {
            int l = *a.begin(), r = *b.begin();
            if (l < r)
            {
                ans++;
                a.erase(l); a.erase(l + 500);
                b.erase(l + 1000); b.erase(l + 1500);
            }
            else
            {
                b.erase(r); b.erase(r + 500);
                a.erase(r + 1000); a.erase(r + 1500);
            }
        }

        cout << ans << "\n";
    }
}