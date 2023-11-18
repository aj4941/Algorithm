#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int a[N];
bool cache[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int s; cin >> s;

    queue<int> q; q.push(s); cache[s] = true;
    int ans = 1;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        int nv1 = v - a[v], nv2 = v + a[v];
        if (nv1 >= 1 && !cache[nv1])
        {
            q.push(nv1); ans++;
            cache[nv1] = true;
        }
        if (nv2 <= n && !cache[nv2])
        {
            q.push(nv2); ans++;
            cache[nv2] = true;
        }
    }

    cout << ans;
}