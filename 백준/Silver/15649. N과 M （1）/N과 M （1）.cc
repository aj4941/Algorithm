#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;
int a[10];
bool cache[10];
vector<int> res;

void func(int cnt)
{
    if (cnt == m)
    {
        for (auto to : res)
            cout << to << ' ';
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (cache[i] == false)
        {
            cache[i] = true;
            res.push_back(i);
            func(cnt + 1);
            res.pop_back();
            cache[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    func(0);
}