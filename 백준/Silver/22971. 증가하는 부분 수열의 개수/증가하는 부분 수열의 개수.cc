#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5002;
const ll inf = 998244353;
ll a[N], cnt[N], n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
                cnt[i] += cnt[j];
            cnt[i] %= inf;
        }
        cnt[i]++; cnt[i] %= inf;
        cout << cnt[i] << ' ';
    }
}
