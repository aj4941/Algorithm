#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll x, ll y) {
    return ((y) ? gcd(y, x % y) : x);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int num; cin >> num;
    priority_queue<int> pq;
    for (int i = 0; i < n - 1; i++)
    {
        int x; cin >> x;
        pq.push(x);
    }

    int ans = 0;

    while (pq.size() > 0 && pq.top() >= num)
    {
        int value = pq.top(); pq.pop();
        num += 1; value--;
        if (value > 0) pq.push(value);

        ans++;
    }

    cout << ans;
}