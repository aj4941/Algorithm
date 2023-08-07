#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<string, int> sti;
map<int, string> ist;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        if (!sti.count(s))
        {
            sti[s] = i;
            ist[i] = s;
        }
        else
        {
            int pi = sti[s];
            sti[s] = i;
            ist[pi] = "0"; ist[i] = s;
        }
    }

    for (auto to : ist)
    {
        if (to.second == "0") continue;
        cout << to.second << "\n";
        n--;
        if (n == 0)
            break;
    }
}