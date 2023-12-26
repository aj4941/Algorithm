#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
typedef tuple<ll, ll, ll> tll;

int main(void)
{
    vector<pair<int, string>> t1, t2;
    for (int i = 0; i < 3; i++)
    {
        int a, b; cin >> a >> b;
        string c; cin >> c;
        t1.push_back({ b % 100, c });
        t2.push_back({ a, c });
    }

    string ans1 = "", ans2 = "";
    sort(t1.begin(), t1.end());
    for (auto to : t1)
        ans1 += to_string(to.first);

    sort(t2.rbegin(), t2.rend());
    for (auto to : t2)
        ans2 += to.second[0];

    cout << ans1 << "\n" << ans2;
}