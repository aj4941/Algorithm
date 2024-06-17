#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    deque<int> dq;
    for (int i = 0; i < n; i++) dq.push_back(i + 1);

    cout << "<";

    while (dq.size())
    {
        for (int i = 0; i < k - 1; i++)
        {
            int x = dq.front(); dq.pop_front();
            dq.push_back(x);
        }

        cout << dq.front();
        dq.pop_front();

        if (dq.size() == 0) cout << ">";
        else cout << ", ";
    }
}