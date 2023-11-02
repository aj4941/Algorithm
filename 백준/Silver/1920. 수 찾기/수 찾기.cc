#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ll a[120000];
    ll n, m; cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        ll find;
        scanf("%lld", &find);
        ll left = 0, right = n - 1;
        bool flag = false;
        while(left <= right)
        {
            ll mid = (left + right) / 2;
            if(a[mid] == find)
            {
                flag = true;
                break;
            }
            else if(a[mid] < find) left = mid + 1;
            else right = mid - 1;
        }
        if(flag) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}